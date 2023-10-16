#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

#include "Entity.h"

class Item : public Entity
{
    private:
    int damageBonus;
    int armourBonus;
    int specialAttribute;

    public:
    Item();
    Item(std::string _name, int _damageBonus, int _armourBonus, int _specialAttribute);
    ~Item();
    int getDamageBonus();
    int getArmourBonus();
    int getSpecialAttribute();
    int takeDamage(int damage);
};

#endif // ITEM_H
