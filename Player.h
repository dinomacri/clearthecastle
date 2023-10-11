#ifndef PLAYER_H
#define PLAYER_H

#include "Item.h"
#include "Mob.h"
#include <array>

class Boss;

class Player: public Mob
{
    protected:
    std::array<Item, 3> inventory; 
    int specialAbility;

    public:
    Player();
    Player(std::string name, int baseHealth, int baseDamage, int baseArmour, int specialAbility);
    Item getInventorySlot(int index);
    void printInventory();
    int getTotalHealth();
    int getTotalDamage();
    int getTotalArmour();
    
    void equipItem(Item* item);

    void attack(Mob& target) override;
    void receiveAttack(int damage) override;

};


#endif // PLAYER_H
