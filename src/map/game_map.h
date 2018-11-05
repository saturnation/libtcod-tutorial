//
// Created by Saturnation on 2/11/2018.
//

#ifndef LIBTCOD_TUTORIAL_GAME_MAP_H
#define LIBTCOD_TUTORIAL_GAME_MAP_H

#include <libtcod/fov_types.h>

struct tile;

struct game_map {
    int width;
    int height;
    struct tile **map;
} ;

#include "tile.h"
#include "rectangle.h"
#include "../data/list.h"


struct game_map *create_game_map(int width, int height);

bool is_blocked(struct game_map *map, int x, int y);

void create_room(struct game_map *map, struct rectangle *room);

void make_map(struct game_map *map,
              int make_rooms,
              int room_min_size,
              int room_max_size,
              int map_width,
              int map_height,
              struct entity *player,
              struct entity_list *e,
              int max_monsters_per_room);

void create_h_tunnel(struct game_map *map, int x1, int x2, int y);

void create_v_tunnel(struct game_map *map, int x, int y1, int y2);

void move_toward(struct entity *e, struct entity *target, struct game_map *map, struct entity_list *entity_list);

void basic_ai_monster_turn(struct entity* e, struct entity *target, TCOD_Map *fov_map, struct game_map *map, struct entity_list *entity_list);

double distance_to(struct entity *e, struct entity *target);
#endif //LIBTCOD_TUTORIAL_GAME_MAP_H
