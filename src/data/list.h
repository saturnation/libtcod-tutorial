//
// Created by Saturnation on 3/11/2018.
//

#ifndef LIBTCOD_TUTORIAL_LIST_H
#define LIBTCOD_TUTORIAL_LIST_H

#include "../entity.h"

struct node {
    entity *data;
    struct node *next;
};

typedef struct node entity_list;

#endif //LIBTCOD_TUTORIAL_LIST_H
