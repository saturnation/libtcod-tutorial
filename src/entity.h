//
// Created by Saturnation on 2/11/2018.
//

#ifndef LIBTCOD_TUTORIAL_ENTITY_H
#define LIBTCOD_TUTORIAL_ENTITY_H

#include <libtcod/color.h>

typedef struct {
    int x;
    int y;
    char c;
    TCOD_color_t color;
    char* name;
    bool blocks;
} entity;

#include "data/list.h"
#include "map/game_map.h"

entity* create_entity(int x, int y, char c, TCOD_color_t color, char* name, bool blocks);

void move(game_map* map, entity *e, int dx, int dy);

entity* get_blocking_entities_at_location(entity_list *e, int destination_x, int destination_y);

#endif //LIBTCOD_TUTORIAL_ENTITY_H
