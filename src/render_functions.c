//
// Created by Saturnation on 2/11/2018.
//

#include <libtcod/console.h>
#include <libtcod.h>
#include <stdio.h>
#include "render_functions.h"
#include "entity.h"
#include "map/game_map.h"
#include "map/tile.h"

void clear_entity(TCOD_console_t con, struct entity *e) {
    TCOD_console_put_char(con, e->x, e->y, ' ', TCOD_BKGND_NONE);
}

void draw_entity(TCOD_console_t con, struct entity *e, TCOD_Map* fov_map) {
    if (TCOD_map_is_in_fov(fov_map, e->x, e->y)) {
        TCOD_console_set_default_foreground(con, e->color);
        TCOD_console_put_char(con, e->x, e->y, e->c, TCOD_BKGND_NONE);
    }
}

void clear_all(TCOD_console_t con, struct entity_list *e) {
    struct entity_list *curr = e;
    while (curr != NULL) {
        clear_entity(con, curr->data);
        curr = curr->next;
    }
}

void render_all(TCOD_console_t con,
                struct entity_list *e,
                struct game_map *map,
                TCOD_Map *fov_map,
                bool fov_recompute,
                int width,
                int height,
                TCOD_color_t *color) {
    if (fov_recompute) {
        for (int y = 0; y < map->height; y++) {
            for (int x = 0; x < map->width; x++) {
                bool visible = TCOD_map_is_in_fov(fov_map, x, y);
                bool wall = map->map[y][x].blocked_sight;
                if (visible) {
                    if (wall) {
                        TCOD_console_set_char_background(con, x, y, color[LIGHT_WALL], TCOD_BKGND_SET);
                    } else {
                        TCOD_console_set_char_background(con, x, y, color[LIGHT_GROUND], TCOD_BKGND_SET);
                    }
                    map->map[y][x].explored = true;
                } else if (map->map[y][x].explored){
                    if (wall) {
                        TCOD_console_set_char_background(con, x, y, color[DARK_WALL], TCOD_BKGND_SET);
                    } else {
                        TCOD_console_set_char_background(con, x, y, color[DARK_GROUND], TCOD_BKGND_SET);
                    }
                }
            }
        }
    }

    struct entity_list *curr = e;
    while (curr != NULL) {
        draw_entity(con, curr->data, fov_map);
        curr = curr->next;
    }
    // blit from con to root console
    TCOD_console_blit(con, 0, 0, width, height, 0, 0, 0, 1.0, 1.0);
}


