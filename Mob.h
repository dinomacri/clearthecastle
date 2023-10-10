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
    int getBaseHealth();
    int getCurrentHealth();
    void takeDamage(int damage);

    int getBaseArmour();
    
    int getBaseDamage();

    void fight(Mob& target_player, Mob& target_boss);
    virtual void attack(Mob& target) = 0;
    virtual void receiveAttack(int damage) = 0;

};

#endif // MOB_H
