#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

#include "Entity.h"

class Item : public Entity
{
    private:
    int healthBonus;
    int damageBonus;
    int armourBonus;
    int specialAttribute;

    public:
    Item();
    Item(std::string _name, int _healthBonus, int _strengthBonus, int _armourBonus, int _specialAttribute);
    ~Item();
    int getHealthBonus();
    int getDamageBonus();
    int getArmourBonus();
    int getSpecialAttribute();
};

#endif // ITEM_H
