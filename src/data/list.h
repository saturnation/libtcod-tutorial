//
// Created by Saturnation on 3/11/2018.
//

#ifndef LIBTCOD_TUTORIAL_LIST_H
#define LIBTCOD_TUTORIAL_LIST_H


struct entity;

struct entity_list {
    struct entity *data;
    struct entity_list *next;
};

#include "../entity.h"

struct entity *get_blocking_entities_at_location(struct entity_list *e, int destination_x, int destination_y);

#endif //LIBTCOD_TUTORIAL_LIST_H
