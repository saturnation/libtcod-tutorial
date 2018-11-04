//
// Created by Doug on 3/11/2018.
//

#include <libtcod/fov_types.h>
#include "game_map.h"

#ifndef LIBTCOD_TUTORIAL_FOV_H
#define LIBTCOD_TUTORIAL_FOV_H

TCOD_Map* initialize_fov(game_map *map);
void recompute_fov(TCOD_Map* fov_map, int x, int y, int radius, bool light_walls, int algorithm);

#endif //LIBTCOD_TUTORIAL_FOV_H
