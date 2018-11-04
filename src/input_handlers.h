//
// Created by Doug on 2/11/2018.
//

#include <libtcod/console_types.h>

#ifndef LIBTCOD_TUTORIAL_INPUT_HANDLERS_H
#define LIBTCOD_TUTORIAL_INPUT_HANDLERS_H

#define NO_ACTION -1

#define MOVE_UP 0
#define MOVE_DOWN 1
#define MOVE_LEFT 2
#define MOVE_RIGHT 3

#define FULLSCREEN 4
#define EXIT 5

int handle_keys(TCOD_key_t *k);

#endif //LIBTCOD_TUTORIAL_INPUT_HANDLERS_H
