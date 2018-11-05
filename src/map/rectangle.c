//
// Created by Saturnation on 2/11/2018.
//

#include <stddef.h>
#include <malloc.h>
#include "rectangle.h"

struct rectangle *create_rectangle(int x, int y, int width, int height) {
    struct rectangle* rect = malloc(sizeof(struct rectangle));
    rect->x1 = x;
    rect->y1 = y;
    rect->x2 = x + width;
    rect->y2 = y + height;
}

int* center(struct rectangle *rectangle) {
    int* result = malloc(sizeof(int) * 2);
    result[0] = (rectangle->x1 + rectangle->x2) / 2;
    result[1] = (rectangle->y1 + rectangle->y2) / 2;
    return result;
}

bool intersect(struct rectangle *r1, struct rectangle *r2) {
    return (r1->x1 <= r2->x2 && r1->x2 >= r2->x1
         && r1->y1 <= r2->y2 && r1->y2 >= r2->y1);
}
