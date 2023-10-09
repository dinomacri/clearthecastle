#include "Boss.h"
#include "Mob.h"
#include "Player.h"
#include "Item.h"
#include <iostream>
#include <string>

Player::Player()
{
    this->name = "";
    location[0] = 0;
    location[1] = 0;
    this-> baseHealth = 0;
    this -> baseDamage = 0;
    this -> baseArmour = 0;
    this -> specialAbility = 0;
    currentHealth = 0;
    currentDamage = 0;
    currentArmour = 0;
};
// actual constructor
Player::Player(std::string name, int xCord, int yCord, int baseHealth, int baseDamage, int baseArmour,int specialAbility)
{
    this->name = name;
    location[0] = xCord;
    location[1] = yCord;
    this-> baseHealth = baseHealth;
    this -> baseDamage = baseDamage;
    this -> baseArmour = baseArmour;
    this -> specialAbility = specialAbility;
    currentHealth = baseHealth;
    currentDamage = baseDamage;
    currentArmour = baseArmour;
    
}

// get inventory, passing in the index
Item Player::getInventory(int index)
{
    if (index >= 0 && index < 3)
    {
        return inventory[index];
    }
    else
    {
        // Handle the case where the index is out of bounds, e.g., return a default item or throw an exception.
        // This depends on your application's requirements.
        // Here's an example of returning a default Item:
        return Item(); // Assuming Item has a default constructor
    }
}

// displaying the inventory 
void Player::displayInventory()
{
    for(int i = 0; i < 3; i++)
    {
        std::string ItemName = inventory[i].getName();
         std::cout << ItemName << std::endl;
    }
};


//player take damage function, passing in the damage the boss will take
// this function will be called in the defend function
void Player::PlayerTakeDamage(int damage)
{
    // only armour takes damage
   
    if (currentArmour > damage)
    {
        currentArmour -= damage;
        
        std::cout << name << "'s Armour has protected their health but taken " << damage << " damage. Remaining Armour: " << currentArmour << "\n";
    };

    // only health takes damage

    if (currentArmour == 0)
    {
        currentHealth -= damage;
        std::cout << name << "'s Armour is depleted, their health has taken " << damage << " damage. Remaining Health: " << currentHealth << "\n";
    };

    // armour and health take damage

    if ((currentArmour < damage) && (currentArmour > 0))
    {
        int A = currentArmour - damage;
        currentHealth += A;
        currentArmour = 0;
        std::cout << name << "'s Armour was depleted by the attack, their health has taken " << -A << " damage. Remaining Health: " << currentHealth << "\n";
        
    };

    
    
    
    
};


//attack function
//passes in a pointer to the boss and the current damage of the player
void Player::PlayerAttack(Boss *Boss, int currentDamage)
{
    Boss->BossTakeDamage(currentDamage);
    
    std::cout << Player::getName() << " attacks "  << Boss->getName() <<"!\n";

};

// defend function, takes the players special ability, divides it by 10 and multiplies that by damage. possible error with using ints and dividing by 10
void Player::PlayerDefend(int damage)
{
    int damageModifier = specialAbility;
    damageModifier = damage * (damageModifier/10);
    PlayerTakeDamage(damageModifier);


}; 


