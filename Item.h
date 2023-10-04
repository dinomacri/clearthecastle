#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"
#include <iostream>
#include <string>

class Item : public Entity
{
    private:
    int healthBonus;
    int strengthBonus;
    int armourBonus;
    int specialAttribute;

    public:
    Item();
    Item(std::string name, int xCord, int yCord, int healthBonus, int strengthBonus, int armourBonus, int specialAttribute);
    int getHealthBonus();
    int getStrengthBonus();
    int getArmourBonus();
    int getSpecialAttribute();
    


};

#endif // ITEM_H
