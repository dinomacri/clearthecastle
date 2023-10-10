#include <iostream>
#include <string>
#include "Player.h"
#include "Boss.h"

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

    inventory.fill(Item("empty", 0, 0, 0, 0, 0, 0));

    
};

Player::Player(std::string name, int xCord, int yCord, int baseHealth, int baseDamage, int baseArmour, int specialAbility)
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
    
    inventory.fill(Item("empty", 0, 0, 0, 0, 0, 0));
}

void Player::attack(Mob& target)
{
    std::cout << std::endl;
    std::cout << "You attack " << target.getName() << std::endl;
    target.receiveAttack(5);
}

void Player::receiveAttack(int damage)
{
    std::cout << std::endl;
    this->takeDamage(damage);
    std::cout << "Boss has struck you for " << damage << " damage !" << std::endl;
    std::cout << this->getName() << "'s health is now: " << this->getCurrentHealth() << std::endl;
}

int Player::getTotalDamage() {
    int totalDamage = 0;

    for (int i = 0; i < 3; i++)
    {
        totalDamage = totalDamage + inventory[i].getHealthBonus();
    }
    
    return baseDamage+totalDamage;
}

int Player::getTotalArmour() {
    int totalArmour = 0;

    for (int i = 0; i < 3; i++)
    {
        totalArmour = totalArmour + inventory[i].getArmourBonus();
    }
    
    return baseArmour+totalArmour;
}

int Player::getTotalHealth() {
    int totalHealth = 0;

    for (int i = 0; i < 3; i++)
    {
        totalHealth = totalHealth + inventory[i].getHealthBonus();
    }
    
    return baseHealth+totalHealth;
}

void Player::equipItem(Item item)
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
        inventory[slot_index] = item;
    }
    else
    {
        std::cout << "This slot is full. Consider dropping an item." << std::endl;
    }
}

Item Player::getInventorySlot(int index)
{
    if (index >= 0 && index < 3)
    {
        return inventory[index];
    }
    else
    {
        std::cout << "Index out of bounds";
        return Item();
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