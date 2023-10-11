#include "Item.h"
#include <iostream>
#include <string>

Item::Item()
{
    name = "default";

    healthBonus = 0;
    damageBonus = 0;
    armourBonus = 0;
    specialAttribute = 0;
}

Item::~Item()
{
    #ifdef DEBUG
    std::cout << "DEBUG: " << getName() << " was destroyed (Item)\n";
    #endif
}

Item::Item(std::string name, int healthBonus, int damageBonus, int armourBonus, int specialAttribute)
{
    this->name = name;
    this->healthBonus = healthBonus;
    this->damageBonus = damageBonus;
    this->armourBonus = armourBonus;
    this->specialAttribute = specialAttribute;
}

std::string Item::getName()
{
    return name;
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
