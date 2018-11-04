//
// Created by Saturnation on 4/11/2018.
//

#ifndef LIBTCOD_TUTORIAL_FIGHTER_H
#define LIBTCOD_TUTORIAL_FIGHTER_H

typedef struct {
    int max_hp;
    int hp;
    int defense;
    int power;
} fighter;

fighter *create_fighter(int hp, int defense, int power);
#endif //LIBTCOD_TUTORIAL_FIGHTER_H
