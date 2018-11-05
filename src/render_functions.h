//
// Created by Saturnation on 2/11/2018.
//

#include <libtcod/console_types.h>
#include <libtcod/fov_types.h>
#include "entity.h"
#include "map/game_map.h"
#include "data/list.h"

#ifndef LIBTCOD_TUTORIAL_RENDER_FUNCTIONS_H
#define LIBTCOD_TUTORIAL_RENDER_FUNCTIONS_H

void render_all(TCOD_console_t con,
                struct entity_list *e,
                struct game_map* map,
                TCOD_Map* fov_map,
                bool fov_recompute,
                int width,
                int height,
                TCOD_color_t* colors);
void clear_all(TCOD_console_t con, struct entity_list *e);
void draw_entity(TCOD_console_t con, struct entity* e, TCOD_Map* fov_map);
void clear_entity(TCOD_console_t con, struct entity* e);

#endif //LIBTCOD_TUTORIAL_RENDER_FUNCTIONS_H
