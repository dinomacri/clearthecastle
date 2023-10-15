#include <iostream>
#include <string>

#include "Item.h"
#include "Logger.h"

Logger logger;

int main() {
    
    std::cout<< "Item Test 1/5: Initialise item" << std::endl;
    Item chestplate("plate", 0, 0, 4, 0);
    int armourBonus = chestplate.getArmourBonus(); // Get the armour bonus

    // Print the armour bonus to the console
    std::cout << "Armour Bonus: " << armourBonus << std::endl;

    std::cout<< "Item Test 2/5: gethealthbonus()" << std::endl;
    chestplate.getHealthBonus();
    if (chestplate.getHealthBonus() != 0)
    {
        return 1;
    }

    std::cout<< "Item Test 3/5: getDamageBonus()" << std::endl;
    chestplate.getDamageBonus();
    if (chestplate.getDamageBonus() != 0)
    {
        return 1;
    }

    std::cout<< "Item Test 4/5: getArmourBonus()" << std::endl;
    chestplate.getArmourBonus();
    if (chestplate.getArmourBonus() != 4)
    {
        return 1;
    }

     std::cout<< "Item Test 5/5: getSpecialAttribute()" << std::endl;
    chestplate.getSpecialAttribute();
    if (chestplate.getSpecialAttribute() != 0)
    {
        return 1;
    }

    return 0;
}
