//
// Created by Doug on 2/11/2018.
//

#include "tile.h"

void create_tile(tile *t, bool blocked, bool blocked_sight) {
    t->blocked = blocked;
    t->blocked_sight = blocked_sight;
}
