#ifndef PLAYER_H
#define PLAYER_H

#include "Boss.h"
#include "Mob.h"
#include "Item.h"
class Player: public Mob
{
    protected:
    Item inventory[3]; 
    int specialAbility;

    public:
    Player();
    Player(std::string name, int xCord, int yCord, int baseHealth, int baseDamage, int baseArmour, int specialAbility);
    Item getInventory(int index);
    void displayInventory();
    int getTotalHealth();
    int getTotalDamage();
    void PlayerTakeDamage(int damage);
    void PlayerAttack(Boss *Boss, int currentDamage);
    void PlayerDefend(int damage);
    
};


#endif // PLAYER_H
