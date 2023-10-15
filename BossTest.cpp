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
    Player playerTest;
    Boss bossTest;

    std::cout<< "Boss Test 1/10: getBaseArmour() \n";
    bossTest = Boss("bossTest", 0, 0, 10, "deathmessage");
    std::cout << bossTest.getBaseArmour() << std::endl;
    if (bossTest.getBaseArmour() != 10)
    {
        return 1;
    }

    std::cout<< "Boss Test 2/10: getBaseHealth() \n";
    bossTest = Boss("bossTest", 10, 0, 0, "deathmessage");
    std::cout << bossTest.getBaseHealth() << std::endl;
    if (bossTest.getBaseHealth() != 10)
    {
        return 1;
    }
    
    std::cout<< "Boss Test 3/10: getBaseDamage() \n";
    bossTest = Boss("bossTest", 0, 10, 0, "deathmessage");
    std::cout << bossTest.getBaseDamage() << std::endl;
    if (bossTest.getBaseDamage() != 10)
    {
        return 1;
    }

    std::cout<< "Boss Test 4/10: getCurrentHealth() \n";
    bossTest = Boss("bossTest", 10, 0, 0, "deathmessage");
    std::cout << bossTest.getCurrentHealth() << std::endl;
    if (bossTest.getCurrentHealth() != 10)
    {
        return 1;
    }

    std::cout<< "Boss Test 5/10: takeDamage() health and armour \n";
    // damage equals armour
    bossTest = Boss("bossTest", 10, 0, 5, "deathmessage");
    bossTest.takeDamage(5);
    if (bossTest.getCurrentArmour() != 0)
    {
        return 1;
    }
    if (bossTest.getCurrentHealth() != 10)
    {
        return 1;
    }

    // damage exceeds armour
    bossTest = Boss("bossTest", 10, 0, 5, "deathmessage");
    bossTest.takeDamage(10);
    if (bossTest.getCurrentArmour() != 0)
    {
        return 1;
    }
    if (bossTest.getCurrentHealth() != 5)
    {
        return 1;
    }

    // damage exceeds armour and health (kill)
    bossTest = Boss("bossTest", 10, 0, 5, "deathmessage");
    bossTest.takeDamage(20);
    if (bossTest.getCurrentArmour() != 0)
    {
        return 1;
    }
    if (bossTest.getCurrentHealth() != -5)
    {
        return 1;
    }

    std::cout<< "Boss Test 6/10: setters() \n";
    playerTest = Player("playerTest", 0, 0, 0, 0);
    playerTest.setCurrentArmour(10);
    playerTest.setCurrentHealth(10);
    std::cout << playerTest.getCurrentArmour() << std::endl;
    std::cout << playerTest.getCurrentHealth() << std::endl;
    if (playerTest.getCurrentArmour() != 10)
    {
        return 1;
    }
    if (playerTest.getCurrentHealth() != 10)
    {
        return 1;
    }

    std::cout<< "Boss Test 7/10: fight, player dies \n";
    bossTest = Boss("bossTest", 10, 20, 0, "deathmessage");
    playerTest = Player("playerTest", 10, 5, 5, 0);
    
    playerTest.fight(playerTest, bossTest);

    std::cout<< "Boss Test 8/10: receive attack \n";
    bossTest = Boss("bossTest", 10, 10, 10, "deathmessage");
    bossTest.receiveAttack(10);
    if (bossTest.getCurrentArmour() != 0)
    {
        return 1;
    }

     std::cout<< "Boss Test 9/10: getDeathMessage() \n";
     bossTest = Boss("bosstest", 0, 0, 0, "deathmessage");
     bossTest.getDeathMessage();
     if(bossTest.getDeathMessage() != "deathmessage")
     {
        return 1;
     }

     std::cout<< "Boss Test 10/10: attack() \n";
     bossTest = Boss("bossTest", 10, 10, 0, "deathmessage");
     playerTest = Player("playerTest", 10, 10, 0, 0);
     bossTest.attack(playerTest);
     if(playerTest.getCurrentArmour() != 0)
     {
        return 1;
     }
     if(playerTest.getCurrentArmour() != 10)
     {
        return 1;
     }

}
    




