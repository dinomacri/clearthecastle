#ifndef MOB_H
#define MOB_H
#include "Entity.h"
#include <iostream>
#include <string>

class Mob : public Entity
{

    protected:
    //member variables
    int baseHealth;
    int baseDamage;
    int baseArmour;
    int currentArmour;
    int currentHealth;
    int currentDamage;
 

    public:
    // member functions
    int getCurrentHealth();
    int getBaseHealth();
    void setCurrentHealth(int newHealth);
    

    int getCurrentArmour();
    int getBaseArmour();
    void setCurrentArmour(int newArmour);
    
    int getCurrentDamage();
    int getBaseDamage();
    void setCurrentDamage(int newDamage);
    

};

#endif // MOB_H
