//
// Created by Saturnation on 4/11/2018.
//

#include <stdlib.h>
#include "fighter.h"

fighter *create_fighter(int hp, int defense, int power) {
    fighter *f = malloc(sizeof(fighter));
    f->hp = hp;
    f->defense = defense;
    f->power = power;
    return f;
}
