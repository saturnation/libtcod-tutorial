//
// Created by Saturnation on 2/11/2018.
//

#ifndef LIBTCOD_TUTORIAL_ENTITY_H
#define LIBTCOD_TUTORIAL_ENTITY_H

#include <libtcod/color.h>
#include <libtcod/fov_types.h>

struct game_map;
struct entity_list;

struct entity {
    int x;
    int y;
    char c;
    TCOD_color_t color;
    char *name;
    bool blocks;
    struct fighter *fighter;

    void (*ai_action)(struct entity *, struct entity *, TCOD_Map *, struct game_map *, struct entity_list *);
};

#include "components/fighter.h"
#include "map/game_map.h"
#include "data/list.h"

struct entity *create_entity(int x,
                             int y,
                             char c,
                             TCOD_color_t color,
                             char *name,
                             bool blocks,
                             struct fighter *fighter,
                             void(*ai_action)(struct entity *,
                                              struct entity *, TCOD_Map *,
                                              struct game_map *,
                                              struct entity_list *));

void move(struct entity *e, int dx, int dy);

#endif //LIBTCOD_TUTORIAL_ENTITY_H
