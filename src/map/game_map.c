//
// Created by Saturnation on 2/11/2018.
//

#include <stddef.h>
#include <malloc.h>
#include <w32api/minmax.h>
#include <libtcod/mersenne_types.h>
#include <libtcod/mersenne.h>
#include <math.h>
#include <libtcod.h>
#include <stdio.h>
#include "game_map.h"

struct game_map *create_game_map(int width, int height) {
    struct game_map *map = malloc(sizeof(struct game_map));
    map->width = width;
    map->height = height;
    map->map = malloc(sizeof(struct tile *) * height);
    for (int y = 0; y < height; y++) {
        map->map[y] = malloc(sizeof(struct tile) * width);
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            map->map[y][x].blocked = true;
            map->map[y][x].blocked_sight = true;
            map->map[y][x].explored = false;
        }
    }
    return map;
}

bool is_blocked(struct game_map *map, int x, int y) {
    return map->map[y][x].blocked;
}


void carve_out(struct game_map *map, int x, int y) {
    map->map[y][x].blocked = false;
    map->map[y][x].blocked_sight = false;
}

void create_room(struct game_map *map, struct rectangle *room) {
    for (int y = room->y1 + 1; y < room->y2; y++) {
        for (int x = room->x1 + 1; x < room->x2; x++) {
            carve_out(map, x, y);
        }
    }

}

void place_entities(struct game_map *map, struct rectangle *room, struct entity_list *e, int max_monsters_per_room) {
    TCOD_random_t rng = TCOD_random_get_instance();
    int number_of_monsters = TCOD_random_get_int(rng, 0, max_monsters_per_room);
    int i = 0;
    while (i < number_of_monsters) {
        int x = TCOD_random_get_int(rng, room->x1 + 1, room->x2 - 1);
        int y = TCOD_random_get_int(rng, room->y1 + 1, room->y2 - 1);
        struct entity_list *curr = e;
        struct entity_list *prev = e;
        bool location_empty = true;
        while (curr != NULL) {
            if (curr->data->x == x && curr->data->y == y) {
                location_empty = false;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (location_empty) {
            prev->next = (struct entity_list *) malloc(sizeof(struct entity_list));
            void (*ai_action)(struct entity *, struct entity *, TCOD_Map *, struct game_map *, struct entity_list *)
                = &basic_ai_monster_turn;
            if (TCOD_random_get_int(rng, 0, 100) < 80) {
                struct fighter *fighter = create_fighter(10, 0, 3);
                prev->next->data = create_entity(x, y, 'o', TCOD_desaturated_green, "Orc", true, fighter, ai_action);
            } else {
                struct fighter *fighter = create_fighter(16, 1, 4);
                prev->next->data = create_entity(x, y, 'T', TCOD_darker_green, "Troll", true, fighter, ai_action);
            }
            i++;
        }
    }
}

void make_map(struct game_map *map,
              int max_rooms,
              int room_min_size,
              int room_max_size,
              int map_width,
              int map_height,
              struct entity *player,
              struct entity_list *e,
              int max_monsters_per_room) {
    struct rectangle rooms[max_rooms];
    int num_rooms = 0;
    TCOD_random_t rng = TCOD_random_get_instance();
    while (num_rooms < max_rooms) {
        int w = TCOD_random_get_int(rng, room_min_size, room_max_size);
        int h = TCOD_random_get_int(rng, room_min_size, room_max_size);
        int x = TCOD_random_get_int(rng, 0, map_width - w - 1);
        int y = TCOD_random_get_int(rng, 0, map_height - h - 1);
        struct rectangle *new_room = create_rectangle(x, y, w, h);
        bool intersects = false;
        for (int i = 0; i < num_rooms; i++) {
            if (intersect(new_room, &rooms[i])) {
                intersects = true;
                break;
            }
        }
        if (!intersects) {
            create_room(map, new_room);
            int *new_center = center(new_room);
            if (num_rooms == 0) {
                player->x = new_center[0];
                player->y = new_center[1];
            } else {
                int *prev_center = center(&rooms[num_rooms - 1]);
                if (TCOD_random_get_int(rng, 0, 1) == 1) {
                    create_h_tunnel(map, prev_center[0], new_center[0], prev_center[1]);
                    create_v_tunnel(map, prev_center[1], new_center[1], new_center[0]);
                } else {
                    create_v_tunnel(map, prev_center[1], new_center[1], prev_center[0]);
                    create_h_tunnel(map, prev_center[0], new_center[0], new_center[1]);
                }
                free(prev_center);
            }
            free(new_center);
            place_entities(map, new_room, e, max_monsters_per_room);
            rooms[num_rooms] = *new_room;
            num_rooms++;
        }
    }
}

void create_h_tunnel(struct game_map *map, int x1, int x2, int y) {
    for (int x = min(x1, x2); x <= max(x1, x2); x++) {
        carve_out(map, x, y);
    }
}

void create_v_tunnel(struct game_map *map, int y1, int y2, int x) {
    for (int y = min(y1, y2); y <= max(y1, y2); y++) {
        carve_out(map, x, y);
    }
}

void move_toward(struct entity *e, struct entity *target, struct game_map *map, struct entity_list *entity_list) {
    int dx = target->x - e->x;
    int dy = target->y - e->y;

    double distance = sqrt(pow(dx, 2) + pow(dy, 2));
    dx = (int) round(dx / distance);
    dy = (int) round(dy / distance);
    if (!is_blocked(map, e->x + dx, e->y + dy)
        || !get_blocking_entities_at_location(entity_list, e->x + dx, e->y + dy)) {
        move(e, e->x + dx, e->y + dy);
    }
}

double distance_to(struct entity *e, struct entity *target) {
    return sqrt(pow(target->x - e->x, 2) + pow(target->y - e->y, 2));
}

void basic_ai_monster_turn(struct entity *e, struct entity *target, TCOD_Map *fov_map, struct game_map *map, struct entity_list *entity_list) {
    if (TCOD_map_is_in_fov(fov_map, e->x, e->y)) {
        if (distance_to(e, target) >= 2) {
            move_toward(e, target, map, entity_list);
        } else if (target->fighter && target->fighter->hp > 0) {
            printf("The %s insults you! Your ego is damaged!\n", e->name);
        }
    }
}
