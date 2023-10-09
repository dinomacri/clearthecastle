#include "Mob.h"
#include <iostream>
#include <string>
// its  getters and setters
int Mob::getBaseHealth()
{
    return baseHealth;
};

int Mob::getCurrentHealth()
{
    return currentHealth;
}

int Mob::getBaseArmour()
{
    return baseArmour;
};

int Mob::getBaseDamage()
{
    return baseDamage;
};

void Mob::takeDamage(int damage)
{
    currentHealth = currentHealth - damage;
};

std::string Mob::getDeathMessage()
{
    return deathMessage;
}