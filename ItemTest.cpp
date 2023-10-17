#include <iostream>
#include <string>
#include <sstream>

#include "Item.h"
#include "Player.h"
#include "Logger.h"

Logger logger;

int main() {
    Player playerTest;
    Item itemTest;

    std::cout<< "Item Test 1/3: Check takeDamage()" << std::endl;
    itemTest = Item("itemTest", 0, 1, 0);
    itemTest.takeDamage(1);
    if (itemTest.getArmourBonus() != 0)
    {
        return 1;
    }

    std::cout<< "Item Test 2/3: Check getTotal functions" << std::endl;
    playerTest = Player("playerTest", 10, 10, 10);
    itemTest = Item("itemTest", 1, 1, 1);

    // redirect std::cin to a custom stream
    std::istringstream inputStringStream("2");
    std::streambuf* originalCinBuffer = std::cin.rdbuf(inputStringStream.rdbuf());

    playerTest.equipItem(&itemTest);

    // restore std::cin to normal buffer
    std::cin.rdbuf(originalCinBuffer);
    
    if (playerTest.getTotalDamage() != 11)
    {
        return 1;
    }
    if (playerTest.getTotalArmour() != 11)
    {
        return 1;
    }
    // if (playerTest.getTotalSpecial() != 11)
    // {
    //     return 1;
    // }

    std::cout<< "Item Test 3/3: Check getTotal functions with damage" << std::endl;
    playerTest = Player("playerTest", 10, 0, 10);
    itemTest = Item("itemTest", 0, 1, 0);

    // redirect std::cin to a custom stream
    inputStringStream.str("2");
    originalCinBuffer = std::cin.rdbuf(inputStringStream.rdbuf());

    playerTest.equipItem(&itemTest);

    // restore std::cin to normal buffer
    std::cin.rdbuf(originalCinBuffer);

    playerTest.takeDamage(1);

    if (playerTest.getCurrentHealth() != 10)
    
    {
        std::cout << playerTest.getCurrentHealth() << std::endl;
        return 1;
    }
    if (playerTest.getTotalArmour() != 10)
    {
        std::cout << playerTest.getTotalArmour() << std::endl;
        return 1;
    }

    playerTest.takeDamage(10);

    if (playerTest.getCurrentHealth() != 10)
    {
        std::cout << playerTest.getCurrentHealth() << std::endl;
        return 1;
    }
    if (playerTest.getTotalArmour() != 0)
    {
        return 1;
    }

    return 0;
}
