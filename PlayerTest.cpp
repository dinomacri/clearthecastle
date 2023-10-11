#include "Player.h"
#include "Mob.h"

#include <iostream>
#include <string>

int main()
{
    std::cout<< "Test Player" << std::endl;
    Player Steve("Steve", 10, 15, 20, 0);

    // Print the armour bonus to the console
    std::cout << Steve.getBaseArmour() << std::endl;

    return 0;
}