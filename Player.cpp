#include <iostream>
#include <string>
#include "Player.h"
#include "Boss.h"
#include "Logger.h"

// #include <windows.h> for windows clients. 
#include <unistd.h>

extern Logger logger;

Player::Player()
{
    Player("default", 1, 1, 1);
};

Player::Player(std::string _name, int _baseHealth, int _baseDamage, int _baseArmour)
{
    name = _name;
    currentHealth = _baseHealth;
    currentDamage = _baseDamage;
    currentArmour = _baseArmour;
    
    inventory.fill(Item("empty",0,0,0));
}

// Player attacks Boss
void Player::attack(Mob& target)
{
    std::cout << "You attack " << target.getName() << std::endl;
    sleep(1);
    target.receiveAttack(this->getTotalDamage());
    sleep(1);
}

// Boss attacks player
void Player::receiveAttack(int damage)
{
    std::cout << "\n";
    this->takeDamage(damage);
    logger.print_boss("You have been struck for " + std::to_string(damage) + " damage !\n\n");
    sleep(1);
    logger.print_player(this->getName() + "'s health is now: " + std::to_string(this->getCurrentHealth()) + "\n");
    sleep(1);
}

int Player::getTotalDamage() {
    int totalDamage = 0;

    for (int i = 0; i < 3; i++)
    {
        totalDamage = totalDamage + inventory[i].getDamageBonus();
    }
    
    return currentDamage+totalDamage;
}

int Player::getTotalArmour() {
    int itemsArmour = 0;

    for (int i = 0; i < 3; i++)
    {
        itemsArmour = itemsArmour + inventory[i].getArmourBonus();
    }
    
    return currentArmour+itemsArmour;
}

void Player::takeDamage(int damage) {
    // Calculate damage and armour for item's in player's inventory.
    for (int i = 0; i < 3; i++)
    {
        try 
        {
            Item* item = &getInventorySlot(i); 
            damage = item->takeDamage(damage);
        } catch (const std::out_of_range& e)
        {
            logger.print_error("getInventorySlot(): Index out of bounds");
        }
    }

    // Calculate damage and armour for player's. 
    if (currentArmour >= damage)
    {
        currentArmour =  currentArmour - damage;
        std::cout << name << "'s armour has protected their health but taken " << damage << " damage. Remaining Armour: " << getTotalArmour() << "\n";
    }

    // no armour, health takes all the damage
    else if (currentArmour <= 0)
    {
        currentHealth = currentHealth -  damage;
        std::cout << name << "'s armour is depleted, their health has taken " << damage << " damage. Remaining Health: " << currentHealth << "\n";
    }

    //armour and health take damage
    else if (currentArmour > 0)
    {
        int remainingDamage = damage - currentArmour;
        currentArmour = 0;
        currentHealth = currentHealth - remainingDamage;
        std::cout << name << "'s armour was depleted by the attack, their health has taken " << remainingDamage << " damage. Remaining Health: " << currentHealth << "\n";
    };
}

void Player::equipItem(Item* item)
{
    // Ideally, this would only allow you to carry one weapon, one armour 'type' etc.
    // However, current functionality allows you to stack 3 swords etc.
    // this is fine. 
    std::cout << std::endl;
    printInventory();
    int slot = -1;
    while (slot <= 0 || slot > 3)
    {
        std::cout << std::endl << "Select a slot: ";
        std::cin >> slot;
    }

    int slot_index = slot-1;

    if (inventory[slot_index].getName() == "empty") {
        inventory[slot_index] = *item;
        std::cout << "\n";
        printInventory();
        std::cout << "\n";
        std::cout << "Total Damage: " << getTotalDamage() << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "This slot is full. Consider dropping an item." << std::endl;
    }
}

Item& Player::getInventorySlot(int index)
{
    if (index >= 0 && index < 3)
    {
        return inventory[index];
    }
    else
    {
        throw std::out_of_range("Index out of bounds");
    }
}

// displaying the inventory 
void Player::printInventory()
{
    for(int i = 0; i < 3; i++)
    {
        std::cout << inventory[i].getName() << " | ";
    }
    std::cout << std::endl;
};