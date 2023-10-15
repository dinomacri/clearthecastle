#include <iostream>
#include <string>

#include "Item.h"
#include "Logger.h"

extern Logger logger;

Item::Item()
{
    Item("empty", 0, 0, 0, 0);
}

Item::Item(std::string _name, int _healthBonus, int _damageBonus, int _armourBonus, int _specialAttribute)
{
    name = _name;
    healthBonus = _healthBonus;
    damageBonus = _damageBonus;
    armourBonus = _armourBonus;
    specialAttribute = _specialAttribute;
}

Item::~Item()
{
    logger.print_debug("~Item() called: " + getName() + " was destroyed\n");
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
