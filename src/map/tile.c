//
// Created by Saturnation on 2/11/2018.
//

#include "tile.h"

void create_tile(struct tile *t, bool blocked, bool blocked_sight) {
    t->blocked = blocked;
    t->blocked_sight = blocked_sight;
}
