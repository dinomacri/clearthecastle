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
    Item(std::string name, int healthBonus, int strengthBonus, int armourBonus, int specialAttribute);
    ~Item();
    int getHealthBonus();
    int getDamageBonus();
    int getArmourBonus();
    int getSpecialAttribute();

    std::string getName();
};

#endif // ITEM_H
