#include "Item.h"
#include <iostream>
#include <string>

Item::Item()
{
    name = "";
    location[0] = 0;
    location[1] = 0;
    healthBonus = 0;
    strengthBonus = 0;
    armourBonus = 0;
    specialAttribute = 0;

}

Item::Item(std::string name, int xCord, int yCord, int healthBonus, int strengthBonus, int armourBonus, int specialAttribute)
{
    this -> name = name;
    location[0] = xCord;
    location[1] = yCord;
    this -> healthBonus = healthBonus;
    this -> strengthBonus = strengthBonus;
    this -> armourBonus = armourBonus;
    this -> specialAttribute = specialAttribute;
}



int Item::getHealthBonus()
{
    return healthBonus;
};

int Item::getArmourBonus()
{
    return armourBonus;
};

int Item::getSpecialAttribute()
{
    return specialAttribute;
};

int Item::getStrengthBonus()
{
    return strengthBonus;
};

