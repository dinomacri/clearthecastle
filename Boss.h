#ifndef BOSS_H
#define BOSS_H
#include <string>

#include "Mob.h"

class Boss : public Mob {

    protected:

    // defining member variables

    std::string deathMessage;

    public:
    //defining constructors
    Boss();
    Boss(std::string name, int xCord, int yCord, int baseHealth, int baseDamage, int baseArmour, std::string deathMessage);
    
    void attack(Mob& target) override;
    void receiveAttack(int damage) override;
    std::string getDeathMessage();
};

#endif // BOSS_H
