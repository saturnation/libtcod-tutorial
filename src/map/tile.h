//
// Created by Doug on 2/11/2018.
//

#include <stdbool.h>
#include <libtcod/color.h>

#ifndef LIBTCOD_TUTORIAL_TILE_H
#define LIBTCOD_TUTORIAL_TILE_H

#define DARK_WALL 0
#define DARK_GROUND 1
#define LIGHT_WALL 2
#define LIGHT_GROUND 3

typedef struct {
    bool blocked;
    bool blocked_sight;
    bool explored;
} tile;

void create_tile(tile* t, bool blocked, bool blocked_sight);
#endif //LIBTCOD_TUTORIAL_TILE_H
