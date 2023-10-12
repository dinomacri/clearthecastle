#include <iostream>
#include <string>

#include "Player.h"
#include "Mob.h"
#include "Logger.h"
#include "Item.h"
#include "Boss.h"

Logger logger;

int main()
{
    Boss steve("steve", 50, 50, 50, "NOOOOOO!!");
    Player greg("greg", 10, 15, 20, 0);

    // Print the armour to the console
    std::cout<< "Test 14 testing getbaseamrour() \n";
    std::cout << greg.getBaseArmour() << std::endl;
    if (greg.getBaseArmour() != 20)
    {
        return 1;
    }

    std::cout<< "Test 15 testing getBaseHealth() \n";
    std::cout << greg.getBaseHealth() << std::endl;
    if (greg.getBaseHealth() != 10)
    {
        return 1;
    }
    
    std::cout<< "Test 16 testing getBaseDamage() \n";
    std::cout << greg.getBaseDamage() << std::endl;
    if (greg.getBaseDamage() != 15)
    {
        return 1;
    }

    std::cout<< "Test 17 testing getCurrentHealth() \n";
    std::cout << greg.getCurrentHealth() << std::endl;
    if (greg.getCurrentHealth() != 10)
    {
        return 1;
    }

    std::cout<< "Test 18 testing takeDamage() \n";
    greg.takeDamage(5);
    std::cout << greg.getCurrentArmour() << std::endl;
    if (greg.getCurrentArmour() != 15)
    {
        return 1;
    }

    std::cout<< "Test 19 testing takeDamage() \n";
    greg.setCurrentHealth(50);
    greg.setCurrentArmour(50);
    greg.takeDamage(50);
    std::cout << greg.getCurrentArmour() << std::endl;
    std::cout << greg.getCurrentHealth() << std::endl;
    if (greg.getCurrentArmour() > 0)
    {
        return 1;
    }
    if (greg.getCurrentHealth() != 50)
    {
        return 1;
    }

    std::cout<< "Test 20 testing takeDamage() \n";
    greg.takeDamage(10);
    std::cout << greg.getCurrentArmour() << std::endl;
    std::cout << greg.getCurrentHealth() << std::endl;
    if (greg.getCurrentArmour() > 0)
    {
        return 1;
    }
    if (greg.getCurrentHealth() != 40)
    {
        return 1;
    }


    std::cout<< "Test 21 testing takeDamage() \n";
    greg.setCurrentHealth(40);
    greg.takeDamage(40);
    std::cout << greg.getCurrentArmour() << std::endl;
    std::cout << greg.getCurrentHealth() << std::endl;
    if (greg.getCurrentArmour() > 0)
    {
        return 1;
    }
    if (greg.getCurrentHealth() > 0)
    {
        return 1;
    }


    std::cout<< "Test 22 testing setters() \n";
    greg.setCurrentArmour(50);
    greg.setCurrentHealth(50);
    greg.setCurrentDamage(50);
    std::cout << greg.getCurrentArmour() << std::endl;
    std::cout << greg.getCurrentHealth() << std::endl;
    std::cout << greg.getCurrentDamage() << std::endl;
    if (greg.getCurrentArmour() != 50)
    {
        return 1;
    }
    if (greg.getCurrentHealth() != 50)
    {
        return 1;
    }
     if (greg.getCurrentDamage() != 50)
    {
        return 1;
    }

    std::cout<< "Test 23 testing fight, boss dies \n";
    greg.fight(greg, steve);
    std::cout<< "done \n";


    std::cout<< "Test 24 testing receive attack \n";

    Player Phil("Phil", 10, 15, 20, 0);
    Phil.receiveAttack(10);
    Phil.getCurrentArmour();
    if (Phil.getCurrentArmour() != 10)
    {
        return 1;
    }

     std::cout<< "Test 25 testing print inventory() \n";
     Phil.printInventory();

     std::cout<< "Test 26 testing equip item() and getinventoryslot() \n";
     Item ChestPlate("plate", 0, 0, 4, 0);
     Phil.equipItem(&ChestPlate);
     Phil.getInventorySlot(0);
     

}