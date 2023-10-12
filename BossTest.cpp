#include <iostream>
#include <string>

#include "Boss.h"
#include "Player.h"
#include "Mob.h"
#include "Item.h"
#include "Entity.h"
#include "Logger.h"

Logger logger;

int main()
{
    Boss greg("greg", 50, 50, 50, "NOOOOOO!!");
    Player Steve("Steve", 10, 15, 20, 0);

    // Print the armour to the console
    std::cout<< "Test 1 testing getbaseamrour() \n";
    std::cout << greg.getBaseArmour() << std::endl;
    if (greg.getBaseArmour() != 50)
    {
        return 1;
    }

    std::cout<< "Test 2 testing getBaseHealth() \n";
    std::cout << greg.getBaseHealth() << std::endl;
    if (greg.getBaseHealth() != 50)
    {
        return 1;
    }
    
    std::cout<< "Test 3 testing getBaseDamage() \n";
    std::cout << greg.getBaseDamage() << std::endl;
    if (greg.getBaseDamage() != 50)
    {
        return 1;
    }

    std::cout<< "Test 4 testing getCurrentHealth() \n";
    std::cout << greg.getCurrentHealth() << std::endl;
    if (greg.getCurrentHealth() != 50)
    {
        return 1;
    }

    std::cout<< "Test 5 testing takeDamage() \n";
    greg.takeDamage(5);
    std::cout << greg.getCurrentArmour() << std::endl;
    if (greg.getCurrentArmour() != 45)
    {
        return 1;
    }

    std::cout<< "Test 6 testing takeDamage() \n";
    greg.takeDamage(50);
    std::cout << greg.getCurrentArmour() << std::endl;
    std::cout << greg.getCurrentHealth() << std::endl;
    if (greg.getCurrentArmour() > 0)
    {
        return 1;
    }
    if (greg.getCurrentHealth() != 45)
    {
        return 1;
    }

    std::cout<< "Test 7 testing takeDamage() \n";
    greg.takeDamage(10);
    std::cout << greg.getCurrentArmour() << std::endl;
    std::cout << greg.getCurrentHealth() << std::endl;
    if (greg.getCurrentArmour() > 0)
    {
        return 1;
    }
    if (greg.getCurrentHealth() != 35)
    {
        return 1;
    }


    std::cout<< "Test 8 testing takeDamage() \n";
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


    std::cout<< "Test 9 testing setters() \n";
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

    std::cout<< "Test 10 testing fight, player dies \n";
    Steve.fight(Steve, greg);
    std::cout<< "done \n";


    std::cout<< "Test 11 testing receive attack \n";
    Boss Phil("Phil", 50, 50, 50, "im ded");
    Phil.receiveAttack(10);
    Phil.getCurrentHealth();
    if (Phil.getCurrentArmour() != 40)
    {
        return 1;
    }

     std::cout<< "Test 12 testing getDeathMessage() \n";
     Phil.getDeathMessage();
     if(Phil.getDeathMessage() != "im ded")
     {
        return 1;
     }

     std::cout<< "Test 13 testing attack() \n";
     Player J("J", 10, 15, 20, 0);
     Phil.attack(J);
     if(J.getCurrentArmour() != 15)
     {
        return 1;
     }

}
    




