//
// Created by Saturnation on 2/11/2018.
//

#include <malloc.h>
#include <stdio.h>
#include "entity.h"

void move(struct entity *e, int dx, int dy) {
    e->x += dx;
    e->y += dy;
}

struct entity *create_entity(int x,
                      int y,
                      char c,
                      TCOD_color_t color,
                      char *name,
                      bool blocks,
                      struct fighter *fighter,
                      void (*ai_action)(struct entity *, struct entity *, TCOD_Map *, struct game_map *, struct entity_list *)) {
    struct entity *e = malloc(sizeof(struct entity));
    e->x = x;
    e->y = y;
    e->c = c;
    e->color = color;
    e->name = name;
    e->blocks = blocks;
    e->fighter = fighter;
    e->ai_action = ai_action;
    return e;
}

