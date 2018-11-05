//
// Created by Saturnation on 2/11/2018.
//

#include <libtcod/console_types.h>

#ifndef LIBTCOD_TUTORIAL_INPUT_HANDLERS_H
#define LIBTCOD_TUTORIAL_INPUT_HANDLERS_H

#define NO_ACTION 0

#define MOVE 1
#define FULLSCREEN 2
#define EXIT 3

typedef struct move_action {
    int dx;
    int dy;
} move_action;

typedef union union_action {
    move_action move;
    bool logic;
} union_action;

struct action {
    int type;
    union_action data;
};

void handle_keys(TCOD_key_t *k, struct action *a);

#endif //LIBTCOD_TUTORIAL_INPUT_HANDLERS_H
