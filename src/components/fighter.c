//
// Created by Saturnation on 4/11/2018.
//

#include <stdlib.h>
#include "fighter.h"

struct fighter *create_fighter(int hp, int defense, int power) {
    struct fighter *f = malloc(sizeof(struct fighter));
    f->hp = hp;
    f->defense = defense;
    f->power = power;
    return f;
}

void take_damage(struct fighter *fighter, int amount) {
    fighter->hp -= amount;
}

void attack(struct entity *attacker, struct entity* target) {
    int damage = attacker->fighter->power - target->fighter->defense;

    if (damage > 0) {
        take_damage(target->fighter, damage);
        printf("%s attack %s for %d hit points.\n", attacker->name, target->name, damage);
    }
}


