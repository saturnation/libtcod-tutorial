//
// Created by Saturnation on 2/11/2018.
//

#include <malloc.h>
#include "entity.h"
#include "map/tile.h"

void move(game_map *map, entity *e, int dx, int dy) {
    e->x += dx;
    e->y += dy;
}

entity *create_entity(int x, int y, char c, TCOD_color_t color, char *name, bool blocks) {
    entity *e = malloc(sizeof(entity));
    e->x = x;
    e->y = y;
    e->c = c;
    e->color = color;
    e->name = name;
    e->blocks = blocks;
    return e;
}

entity *get_blocking_entities_at_location(entity_list *e, int destination_x, int destination_y) {
    entity_list *curr = e;
    while (curr != NULL) {
        entity curr_e = *curr->data;
        if (curr_e.blocks && curr_e.x == destination_x && curr_e.y == destination_y) {
            return curr->data;
        }
        curr = curr->next;
    }
    return NULL;
}
