//
// Created by Saturnation on 3/11/2018.
//

#include <libtcod.h>
#include "fov.h"
#include "game_map.h"
#include "tile.h"

TCOD_Map* initialize_fov(struct game_map *map) {
    TCOD_Map *fov_map = TCOD_map_new(map->width, map->height);
    for (int y = 0; y < map->height; y++) {
        for (int x = 0; x < map->width; x++) {
            TCOD_map_set_properties(fov_map, x, y, !map->map[y][x].blocked_sight, !map->map[y][x].blocked_sight);
        }
    }
    return fov_map;
}

void recompute_fov(TCOD_Map *fov_map, int x, int y, int radius, bool light_walls, int algorithm) {
    TCOD_map_compute_fov(fov_map, x, y, radius, light_walls, algorithm);

}
