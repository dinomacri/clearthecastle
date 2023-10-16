#include <iostream>
#include <sstream>
#include <string>

#include "Player.h"
#include "Mob.h"
#include "Logger.h"
#include "Item.h"
#include "Boss.h"

Logger logger;

int main()
{
    // initialise capture variables to capture cout and write to cin
    std::stringstream outputCapture;
    std::streambuf* originalOutput; 
    std::string capturedOutput;

    Player playerTest;
    Boss bossTest;

    // Print the armour to the console
    std::cout<< "Player Test 1/11: getCurrentArmour() \n";
    playerTest = Player("playerTest", 0, 0, 10, 0);
    if (playerTest.getCurrentArmour() != 10)
    {
        return 1;
    }

    std::cout<< "Player Test 2/11: getCurrentHealth() \n";
    playerTest = Player("playerTest", 10, 0, 0, 0);
    if (playerTest.getCurrentHealth() != 10)
    {
        return 1;
    }
    
    std::cout<< "Player Test 3/11: getBaseDamage() \n";
    playerTest = Player("playerTest", 0, 10, 0, 0);
    if (playerTest.getCurrentDamage() != 10)
    {
        return 1;
    }

    std::cout<< "Player Test 4/21: getCurrentHealth() \n";
    playerTest = Player("playerTest", 10, 0, 0, 0);
    if (playerTest.getCurrentHealth() != 10)
    {
        return 1;
    }

    std::cout<< "Player Test 5/11: takeDamage() health \n";
    playerTest = Player("playerTest", 10, 0, 0, 0);
    playerTest.takeDamage(1);
    if (playerTest.getCurrentHealth() != 9)
    {
        return 1;
    }

    std::cout<< "Player Test 6/11: takeDamage() armour \n";
    playerTest = Player("playerTest", 10, 0, 5, 0);
    playerTest.takeDamage(1);
    if (playerTest.getCurrentHealth() != 10)
    {
        return 1;
    }
    if (playerTest.getCurrentArmour() != 4)
    {
        return 1;
    }

    std::cout<< "Player Test 7/11: takeDamage() health and armour \n";
    // damage equals armour
    playerTest = Player("playerTest", 10, 0, 5, 0);
    playerTest.takeDamage(5);
    if (playerTest.getCurrentArmour() != 0)
    {
        return 1;
    }
    if (playerTest.getCurrentHealth() != 10)
    {
        return 1;
    }

    // damage exceeds armour
    playerTest = Player("playerTest", 10, 0, 5, 0);
    playerTest.takeDamage(10);
    if (playerTest.getCurrentArmour() != 0)
    {
        return 1;
    }
    if (playerTest.getCurrentHealth() != 5)
    {
        return 1;
    }

    // damage exceeds armour and health (kill)
    playerTest = Player("playerTest", 10, 0, 5, 0);
    playerTest.takeDamage(20);
    if (playerTest.getCurrentArmour() != 0)
    {
        return 1;
    }
    if (playerTest.getCurrentHealth() != -5)
    {
        return 1;
    }


    std::cout<< "Player Test 8/11: setters() \n";
    playerTest = Player("playerTest", 0, 0, 0, 0);
    playerTest.setCurrentArmour(50);
    playerTest.setCurrentHealth(50);
    if (playerTest.getCurrentArmour() != 50)
    {
        return 1;
    }
    if (playerTest.getCurrentHealth() != 50)
    {
        return 1;
    }

    std::cout<< "Player Test 9/11: fight, boss dies \n";
    playerTest = Player("playerTest", 100, 100, 0, 0);
    bossTest = Boss("bossTest", 10, 10, 10, "deathmessage");
    playerTest.fight(playerTest, bossTest);

    std::cout << "Press A\n";

    // Redirect std::cout to a stringstream
    originalOutput = std::cout.rdbuf(outputCapture.rdbuf());

    // Call the fight function
    playerTest.fight(playerTest, bossTest);

    // Restore the original std::cout
    std::cout.rdbuf(originalOutput);

    // Get the captured output as a string
    capturedOutput = outputCapture.str();

    // Check if it contains "testphrase" and "slain"
    if (capturedOutput.find("deathmessage") == std::string::npos && capturedOutput.find("slain") == std::string::npos) {
        std::cout << "One or both of 'deathmessage' and 'slain' not found in the output.\n";
    }

    std::cout<< "Player Test 10/11: receive attack \n";
    playerTest = Player("playerTest", 10, 10, 10, 0);
    playerTest.receiveAttack(10);
    playerTest.getCurrentArmour();
    if (playerTest.getCurrentArmour() != 0)
    {
        return 1;
    }

    std::cout<< "Player Test 11/11: print inventory() \n";
    playerTest = Player("playerTest", 0, 0, 0, 0);
    Item* itemTest = new Item("testItem", 0, 0, 0);

    // redirect std::cin to a custom stream
    std::istringstream inputStringStream("2");
    std::streambuf* originalCinBuffer = std::cin.rdbuf(inputStringStream.rdbuf());

    playerTest.equipItem(itemTest);

    // restore std::cin to normal buffer
    std::cin.rdbuf(originalCinBuffer);

    /// Redirect std::cout to a stringstream
    originalOutput = std::cout.rdbuf(outputCapture.rdbuf());

    // Call the fight function
    playerTest.printInventory();

    // Restore the original std::cout
    std::cout.rdbuf(originalOutput);

    // Get the captured output as a string
    capturedOutput = outputCapture.str();

    // Check if it contains "testItem"
    if (capturedOutput.find("testItem") == std::string::npos) {
        std::cout << "'testItem' not found in the output.\n";
        return 1;
    }
}