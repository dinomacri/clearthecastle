#include "Item.h"
#include "Entity.h"
#include <iostream>
#include <string>

Item::Item()
{
    name = "";
    location[0] = 0;
    location[1] = 0;
    healthBonus = 0;
    damageBonus = 0;
    armourBonus = 0;
    specialAttribute = 0;
}

Item::Item(std::string name, int xCord, int yCord, int healthBonus, int damageBonus, int armourBonus, int specialAttribute)
{
    this->name = name;
    location[0] = xCord;
    location[1] = yCord;
    this->healthBonus = healthBonus;
    this->damageBonus = damageBonus;
    this->armourBonus = armourBonus;
    this->specialAttribute = specialAttribute;
}

int Item::getHealthBonus()
{
    return healthBonus;
}

int Item::getArmourBonus()
{
    return armourBonus;
}

int Item::getSpecialAttribute()
{
    return specialAttribute;
}

int Item::getDamageBonus()
{
    return damageBonus;
}
