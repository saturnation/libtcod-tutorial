//
// Created by Saturnation on 4/11/2018.
//
#include "list.h"

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
