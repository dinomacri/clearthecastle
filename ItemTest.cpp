#include <iostream>
#include <string>

#include "Item.h"
#include "Logger.h"

Logger logger;

int main() {
    std::cout<< "test item" << std::endl;
    Item chestplate("plate", 0, 0, 4, 0);
    int armourBonus = chestplate.getArmourBonus(); // Get the armour bonus

    // Print the armour bonus to the console
    std::cout << "Armour Bonus: " << armourBonus << std::endl;

    return 0;
}
