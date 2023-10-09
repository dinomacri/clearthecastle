#ifndef BOSS_H
#define BOSS_H
#include <string>

#include "Mob.h"

class Boss : public Mob {

    protected:
    // defining member variables

    // As you can see, I had some troubles accessing deathMessage() from Boss directly, and interacting with Player.
    // it's now in Mob.

    public:
    //defining constructors
    Boss();
    Boss(std::string name, int xCord, int yCord, int baseHealth, int baseDamage, int baseArmour, std::string deathMessage);
    
    void attack(Mob& target) override;
    void receiveAttack(int damage) override;
};

#endif // BOSS_H
