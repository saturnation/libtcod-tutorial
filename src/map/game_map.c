//
// Created by Saturnation on 2/11/2018.
//

#include <stddef.h>
#include <malloc.h>
#include <w32api/minmax.h>
#include <libtcod/mersenne_types.h>
#include <libtcod/mersenne.h>
#include "game_map.h"
#include "tile.h"
#include "../data/list.h"

game_map *create_game_map(int width, int height) {
    game_map *map = malloc(sizeof(game_map));
    map->width = width;
    map->height = height;
    map->map = malloc(sizeof(tile *) * height);
    for (int y = 0; y < height; y++) {
        map->map[y] = malloc(sizeof(tile) * width);
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

bool is_blocked(game_map *map, int x, int y) {
    return map->map[y][x].blocked;
}


void carve_out(const game_map *map, int x, int y) {
    map->map[y][x].blocked = false;
    map->map[y][x].blocked_sight = false;
}

void create_room(game_map *map, rectangle *room) {
    for (int y = room->y1 + 1; y < room->y2; y++) {
        for (int x = room->x1 + 1; x < room->x2; x++) {
            carve_out(map, x, y);
        }
    }

}

void place_entities(game_map* map, rectangle* room, entity_list *e, int max_monsters_per_room) {
    TCOD_random_t rng = TCOD_random_get_instance();
    int number_of_monsters = TCOD_random_get_int(rng, 0, max_monsters_per_room);
    int i = 0;
    while (i < number_of_monsters) {
        int x = TCOD_random_get_int(rng, room->x1 + 1, room->x2 - 1);
        int y = TCOD_random_get_int(rng, room->y1 + 1, room->y2 - 1);
        entity_list *curr = e;
        entity_list *prev = e;
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
            prev->next = (entity_list *)malloc(sizeof(entity_list));
            if (TCOD_random_get_int(rng, 0, 100) < 80) {
                prev->next->data = create_entity(x, y, 'o', TCOD_desaturated_green, "Orc", true);
            } else {
                prev->next->data = create_entity(x, y, 'T', TCOD_darker_green, "Troll", true);
            }
            i++;
        }
    }
}

void make_map(game_map *map,
              int max_rooms,
              int room_min_size,
              int room_max_size,
              int map_width,
              int map_height,
              entity *player,
              entity_list *e,
              int max_monsters_per_room) {
    rectangle rooms[max_rooms];
    int num_rooms = 0;
    TCOD_random_t rng = TCOD_random_get_instance();
    while (num_rooms < max_rooms) {
        int w = TCOD_random_get_int(rng, room_min_size, room_max_size);
        int h = TCOD_random_get_int(rng, room_min_size, room_max_size);
        int x = TCOD_random_get_int(rng, 0, map_width - w - 1);
        int y = TCOD_random_get_int(rng, 0, map_height - h - 1);
        rectangle *new_room = create_rectangle(x, y, w, h);
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

void create_h_tunnel(game_map *map, int x1, int x2, int y) {
    for (int x = min(x1, x2); x <= max(x1, x2); x++) {
        carve_out(map, x, y);
    }
}

void create_v_tunnel(game_map *map, int y1, int y2, int x) {
    for (int y = min(y1, y2); y <= max(y1, y2); y++) {
        carve_out(map, x, y);
    }
}
