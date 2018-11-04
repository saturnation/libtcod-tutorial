//
// Created by Saturnation on 2/11/2018.
//

#include <malloc.h>
#include <stdio.h>
#include "entity.h"

void move(entity *e, int dx, int dy) {
    e->x += dx;
    e->y += dy;
}

entity *create_entity(int x,
                      int y,
                      char c,
                      TCOD_color_t color,
                      char *name,
                      bool blocks,
                      fighter *fighter,
                      void (*ai_action)(entity *)) {
    entity *e = malloc(sizeof(entity));
    e->x = x;
    e->y = y;
    e->c = c;
    e->color = color;
    e->name = name;
    e->blocks = blocks;
    e->fighter = fighter;
    e->ai_action;
    return e;
}

void basic_ai_monster_turn(entity *e) {
    printf("The %s wonders when it will get to move.\n", e->name);
}


