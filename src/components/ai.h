//
// Created by Saturnation on 4/11/2018.
//

#ifndef LIBTCOD_TUTORIAL_AI_H
#define LIBTCOD_TUTORIAL_AI_H

#include "../entity.h"

typedef struct {
    entity *owner;
} ai;

void take_turn(ai *ai);

#endif //LIBTCOD_TUTORIAL_AI_H
