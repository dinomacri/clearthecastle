#include <iostream>
#include <string>

#include "Item.h"
#include "Logger.h"

extern Logger logger;

Item::Item()
{
    Item("empty", 0, 0, 0);
}

Item::Item(std::string _name, int _damageBonus, int _armourBonus, int _specialAttribute)
{
    name = _name;
    damageBonus = _damageBonus;
    armourBonus = _armourBonus;
    specialAttribute = _specialAttribute;
}

Item::~Item()
{
    logger.print_debug("~Item() called: " + getName() + " was destroyed\n");
}

int Item::getDamageBonus()
{
    return damageBonus;
}

int Item::getArmourBonus()
{
    return armourBonus;
}

int Item::getSpecialAttribute()
{
    return specialAttribute;
}

// returns damage remaining
int Item::takeDamage(int damage)
{
    int remainingDamage = damage; // Initialize remainingDamage to the original damage.

    if (armourBonus >= remainingDamage)
    {
        armourBonus = armourBonus - remainingDamage;

        remainingDamage = 0; // All damage absorbed by armor.
    }
    else if (armourBonus > 0)
    {
        remainingDamage = remainingDamage - armourBonus;
        armourBonus = 0;
    }

    return remainingDamage; // Return any remaining damage after armor and health are considered.
}