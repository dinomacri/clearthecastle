#ifndef MOB_H
#define MOB_H
#include "Entity.h"
#include <iostream>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>
#include <curses.h>
#include <fstream>
class Mob : public Entity
{

    protected:
    //member variables
    // int baseHealth;
    // int baseDamage;
    // int baseArmour;
    int currentArmour;
    int currentHealth;
    int currentDamage;
    

    public:
    int killCounter;
    // member functions
    // int getBaseHealth();
    int getCurrentHealth();

    virtual void takeDamage(int damage);

    // int getBaseArmour();
    int getCurrentArmour();

    int getCurrentDamage();

    // for testing purposes only
    void setCurrentArmour(int newArmour);
    void setCurrentHealth(int newHealth);

    void fight(Mob& target_player, Mob& target_boss);
    //void displayMap();
    virtual void attack(Mob& target) = 0;
    virtual void receiveAttack(int damage) = 0;

};

#endif // MOB_H