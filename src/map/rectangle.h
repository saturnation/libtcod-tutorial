//
// Created by Saturnation on 2/11/2018.
//

#include <stdbool.h>

#ifndef LIBTCOD_TUTORIAL_RECTANGLE_H
#define LIBTCOD_TUTORIAL_RECTANGLE_H

struct rectangle {
    int x1;
    int y1;
    int x2;
    int y2;
};

struct rectangle* create_rectangle(int x, int y, int width, int height);
int* center(struct rectangle* rectangle);
bool intersect(struct rectangle* r1, struct rectangle* r2);

#endif //LIBTCOD_TUTORIAL_RECTANGLE_H
