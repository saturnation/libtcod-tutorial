//
// Created by Saturnation on 2/11/2018.
//

#ifndef LIBTCOD_TUTORIAL_ENTITY_H
#define LIBTCOD_TUTORIAL_ENTITY_H

#include <libtcod/color.h>

#include "components/fighter.h"

typedef struct entity {
    int x;
    int y;
    char c;
    TCOD_color_t color;
    char *name;
    bool blocks;
    fighter *fighter;
    void (*ai_action)(struct entity *);
} entity;

entity *create_entity(int x,
                      int y,
                      char c,
                      TCOD_color_t color,
                      char *name,
                      bool blocks,
                      fighter *fighter,
                      void(*ai_action)(entity *));

void move(entity *e, int dx, int dy);

void basic_ai_monster_turn(entity* e);

#endif //LIBTCOD_TUTORIAL_ENTITY_H
