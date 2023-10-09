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
    std::string deathMessage;
 

    public:
    // member functions
    int getBaseHealth();
    int getCurrentHealth();
    void takeDamage(int damage);

    int getBaseArmour();
    
    int getBaseDamage();

    virtual void attack(Mob& target) = 0;
    virtual void receiveAttack(int damage) = 0;

    std::string getDeathMessage();

};

#endif // MOB_H
