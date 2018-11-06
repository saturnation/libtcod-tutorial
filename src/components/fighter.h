//
// Created by Saturnation on 4/11/2018.
//

#ifndef LIBTCOD_TUTORIAL_FIGHTER_H
#define LIBTCOD_TUTORIAL_FIGHTER_H

#include <stdio.h>
#include "../entity.h"

struct fighter{
    int max_hp;
    int hp;
    int defense;
    int power;
};

struct fighter* create_fighter(int hp, int defense, int power);

void take_damage(struct fighter *fighter, int amount);

void attack(struct entity *attacker, struct entity* target);

#endif //LIBTCOD_TUTORIAL_FIGHTER_H
