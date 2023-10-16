#include <iostream>
#include <string>

#include "Boss.h"
#include "Player.h"
#include "Logger.h"

extern Logger logger;

Boss::Boss()
{
    name = "";
    currentHealth = 0;
    currentDamage = 0;
    currentArmour = 0;
    deathMessage = "";
};

Boss::~Boss()
{
    logger.print_debug("~Boss() called: " + getName() + " was destroyed\n");
}

// actual constructor
Boss::Boss(std::string name, int baseHealth, int baseDamage, int baseArmour, std::string deathMessage)
{
    this->name = name;
    currentHealth = baseHealth;
    currentDamage = baseDamage;
    currentArmour = baseArmour;

    this->deathMessage = deathMessage;

}

// Boss attacks Player
void Boss::attack(Mob& target)
{
    target.receiveAttack(this->getCurrentDamage());
};

// Result of Player attacking Boss
void Boss::receiveAttack(int damage)
{
    std::cout << "He says \"You hit me!!!!\"" << std::endl;

    this->takeDamage(damage);
    std::cout << "You have hit " << this->getName() << " for " << damage << " damage!" << std::endl;
    std::cout << this->getName() << "'s health is now " <<  this->getCurrentHealth() << std::endl;
};

std::string Boss::getDeathMessage()
{
    return deathMessage;
}
