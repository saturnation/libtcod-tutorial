//
// Created by Doug on 2/11/2018.
//

#include <stdbool.h>

#ifndef RL1_RECTANGLE_H
#define RL1_RECTANGLE_H

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} rectangle;

rectangle* create_rectangle(int x, int y, int width, int height);
int* center(rectangle* rectangle);
bool intersect(rectangle* r1, rectangle* r2);

#endif //RL1_RECTANGLE_H
