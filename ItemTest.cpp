
#include "Item.h"
#include <iostream>
#include <string>

int main() {
    std::cout<< "test item" << std::endl;
    Item chestplate("plate", 2, 3, 0, 0, 4, 0);
    int armourBonus = chestplate.getArmourBonus(); // Get the armour bonus

    // Print the armour bonus to the console
    std::cout << "Armour Bonus: " << armourBonus << std::endl;

    return 0;
}
