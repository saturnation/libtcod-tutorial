//
// Created by Doug on 3/11/2018.
//

#ifndef RL1_LIST_H
#define RL1_LIST_H

#include "../entity.h"

struct node {
    entity *data;
    struct node *next;
};

typedef struct node entity_list;

#endif //RL1_LIST_H
