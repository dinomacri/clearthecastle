#ifndef MOB_H
#define MOB_H
#include "Entity.h"
#include <iostream>
#include <string>

class Mob : public Entity
{

    protected:
    int baseHealth;
    int baseDamage;
    int baseArmour;
    int currentArmour;
    int currentHealth;
    int currentDamage;

    public:
    int getCurrentHealth();
    int getBaseHealth();
    void setCurrentHealth(int newHealth);
    void takeDamage();

    int getCurrentArmour();
    int getBaseArmour();
    void setCurrentArmour(int newArmour);
    
    int getCurrentDamage();
    int getBaseDamage();
    void setCurrentDamage(int newDamage);
   
    virtual void attack() = 0;
    virtual void defend() = 0;

};

#endif // MOB_H
