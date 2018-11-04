//
// Created by Saturnation on 2/11/2018.
//

#ifndef LIBTCOD_TUTORIAL_GAME_MAP_H
#define LIBTCOD_TUTORIAL_GAME_MAP_H

#include "tile.h"
typedef struct {
    int width;
    int height;
    tile **map;
} game_map;

#include "rectangle.h"
#include "../entity.h"
#include "../data/list.h"

game_map *create_game_map(int width, int height);

bool is_blocked(game_map *map, int x, int y);

void create_room(game_map *map, rectangle *room);

void make_map(game_map *map,
              int make_rooms,
              int room_min_size,
              int room_max_size,
              int map_width,
              int map_height,
              entity *player,
              entity_list *e,
              int max_monsters_per_room);

void create_h_tunnel(game_map *map, int x1, int x2, int y);

void create_v_tunnel(game_map *map, int x, int y1, int y2);

#endif //LIBTCOD_TUTORIAL_GAME_MAP_H
