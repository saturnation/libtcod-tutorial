//
// Created by Saturnation on 2/11/2018.
//

#include <libtcod/console_types.h>
#include <stdlib.h>
#include "input_handlers.h"



struct action* handle_keys(TCOD_key_t *k) {
    struct action *a = malloc(sizeof(struct action));

    if (k->vk == TCODK_UP) {
        a->type = MOVE;
        a->data.move.dx = 0;
        a->data.move.dy = -1;
        return a;
    } else if (k->vk == TCODK_DOWN) {
        a->type = MOVE;
        a->data.move.dx = 0;
        a->data.move.dy = 1;
        return a;
    } else if (k->vk == TCODK_LEFT) {
        a->type = MOVE;
        a->data.move.dx = -1;
        a->data.move.dy = 0;
        return a;
    } else if (k->vk == TCODK_RIGHT) {
        a->type = MOVE;
        a->data.move.dx = 1;
        a->data.move.dy = 0;
        return a;
    } else if (k->vk == TCODK_ENTER && k->lalt) {
        a->type = FULLSCREEN;
        a->data.logic = true;
        return a;
    } else if (k->vk == TCODK_ESCAPE) {
        a->type = EXIT;
        a->data.logic = true;
        return a;
    }
    a->type = NO_ACTION;
    return a;
}
