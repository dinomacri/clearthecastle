#ifndef BOSS_H
#define BOSS_H
#include "Mob.h"
#include "Player.h"
#include <string>
class Boss: public Mob
{

    protected:
    // defining member variables
    std::string deathMessage;
    std::string Weapon;

    public:
    //defining constructors
    Boss();
    Boss(std::string name, int xCord, int yCord, int baseHealth, int baseDamage, int baseArmour, std::string deathMessage, std::string Weapon);
    
//defining functions
    std::string getDeathMessage();
    std::string getWeapon();
    void bossAttack(Player *Player, int currentDamage);
    void BossDefend(int damage);
    void BossTakeDamage(int damage);
    

};

#endif // BOSS_H
