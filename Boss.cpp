#include "Boss.h"
#include "Mob.h"
#include "Player.h"
#include <iostream>
#include <string>
// default constructor
Boss::Boss()
{
    int xCord, yCord, baseHealth, baseDamage, baseArmour = 0;
    std::string name, deathMessage, Weapon = "";
};

// actual constructor
Boss::Boss(std::string name, int xCord, int yCord, int baseHealth, int baseDamage, int baseArmour, std::string deathMessage, std::string Weapon)
{
    this->name = name;
    location[0] = xCord; // xCord location
    location[1] = yCord; // yCord location
    this-> baseHealth = baseHealth;
    this -> baseDamage = baseDamage;
    this -> baseArmour = baseArmour;
    // setting current stats equal to base stats when created
    currentHealth = baseHealth;
    currentDamage = baseDamage;
    currentArmour = baseArmour;

    this -> deathMessage = deathMessage;
    this -> Weapon = Weapon;

}
//getters
std::string Boss::getDeathMessage()
{
    return deathMessage;

};

std::string Boss::getWeapon()
{
    return Weapon;
};

//attack function
//passes in a pointer to the player and the current damage of the boss
void Boss::bossAttack(Player *Player, int currentDamage)
{
    int damage = currentDamage;
    Player->PlayerTakeDamage(damage);
    std::string weapon  = Boss::getWeapon();
    std::cout << name << " attacks "  << Player->getName() << "with their "<< weapon <<"!\n";

};




//boss take damage function, passing in the damage the boss will take
// this function will be called in the defend function
void Boss::BossTakeDamage(int damage)
{
    // if statements used to ensure the armour takes the hit before the bosses health


  

    // only the armour takes damage
    if (Boss::currentArmour > damage)
    {
        Boss::currentArmour -= damage;
        
        std::cout << name << "'s Armour has protected their health but taken " << damage << " damage. Remaining Armour: " << currentArmour << "\n";
    };


    // no armour, health takes all the damage
    if ( Boss::currentArmour == 0)
    {
         Boss::currentHealth -= damage;
        std::cout << name << "'s Armour is depleted, their health has taken " << damage << " damage. Remaining Health: " << currentHealth << "\n";
    };



    //armour and health take damage
    if (( Boss::currentArmour < damage) && ( Boss::currentArmour > 0))
    {
        int A =  Boss::currentArmour - damage;
         Boss::currentHealth += A;
         Boss::currentArmour = 0;
        std::cout << name << "'s Armour was depleted by the attack, their health has taken " << -A << " damage. Remaining Health: " << currentHealth << "\n";
        
    };
    
};


// defend function, generates a random int, divides it by 10 and multiplies that by damage. possible error with using ints and dividing by 10
void Boss::BossDefend(int damage)
{
    double damageModifier = rand() % 7 + 2;
    damageModifier = damage * (damageModifier/10);
    this->BossTakeDamage(damageModifier);
    


};
