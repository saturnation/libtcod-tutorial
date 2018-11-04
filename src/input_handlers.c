//
// Created by Doug on 2/11/2018.
//

#include <libtcod/console_types.h>
#include "input_handlers.h"

int handle_keys(TCOD_key_t *k) {
    if (k->vk == TCODK_UP) {
        return MOVE_UP;
    } else if (k->vk == TCODK_DOWN) {
        return MOVE_DOWN;
    } else if (k->vk == TCODK_LEFT) {
        return MOVE_LEFT;
    } else if (k->vk == TCODK_RIGHT) {
        return MOVE_RIGHT;
    } else if (k->vk == TCODK_ENTER && k->lalt) {
        return FULLSCREEN;
    } else if (k->vk == TCODK_ESCAPE) {
        return EXIT;
    }
    return NO_ACTION;
}
