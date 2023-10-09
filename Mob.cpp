#include "Mob.h"
#include <iostream>
#include <string>
// its  getters and setters
int Mob::getCurrentHealth()
{
    return currentHealth;
};

int Mob::getBaseHealth()
{
    return baseHealth;
};

void Mob::setCurrentHealth(int newHealth)
{
    currentHealth = newHealth;
};



int Mob::getCurrentArmour()
{
    return currentArmour;
};

int Mob::getBaseArmour()
{
    return baseArmour;
};

void Mob::setCurrentArmour(int newArmour)
{
    currentArmour = newArmour;
};




int Mob::getCurrentDamage()
{
    return currentDamage;
};


int Mob::getBaseDamage()
{
    return baseDamage;
};

void Mob::setCurrentDamage(int newDamage)
{
    currentDamage = newDamage;
};

