#include <iostream>
#include <string>

#include "Item.h"
#include "Logger.h"

Logger logger;

int main() {
    
    std::cout<< "Test 26 test item" << std::endl;
    Item chestplate("plate", 0, 0, 4, 0);
    int armourBonus = chestplate.getArmourBonus(); // Get the armour bonus

    // Print the armour bonus to the console
    std::cout << "Armour Bonus: " << armourBonus << std::endl;

    std::cout<< "Test 26 test gethealthbonus()" << std::endl;
    chestplate.getHealthBonus();
    if (chestplate.getHealthBonus() != 0)
    {
        return 1;
    }

    std::cout<< "Test 27 test getDamageBonus()" << std::endl;
    chestplate.getDamageBonus();
    if (chestplate.getDamageBonus() != 0)
    {
        return 1;
    }

    std::cout<< "Test 28 test getArmourBonus()" << std::endl;
    chestplate.getArmourBonus();
    if (chestplate.getArmourBonus() != 4)
    {
        return 1;
    }

     std::cout<< "Test 29 test getSpecialAttribute()" << std::endl;
    chestplate.getSpecialAttribute();
    if (chestplate.getSpecialAttribute() != 0)
    {
        return 1;
    }

    return 0;
}
