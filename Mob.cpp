#include "Mob.h"
#include <iostream>
#include <string>
#include "Boss.h"
#include "Player.h"
#include "Logger.h"
//#include <opencv2/opencv.hpp> 
//using namespace cv; 
//using namespace std; 

extern Logger logger;

// #include <windows.h> for windows clients.
#include <unistd.h>
int killCounter = 0;

int Mob::getCurrentHealth()
{
    return currentHealth;
}

void Mob::setCurrentHealth(int newHealth)
{
    currentHealth = newHealth;
}

int Mob::getCurrentArmour()
{
    return currentArmour;
}

int Mob::getCurrentDamage()
{
    return currentDamage;
}

void Mob::setCurrentArmour(int newArmour)
{
    currentArmour = newArmour;
}

void Mob::takeDamage(int damage)
{
    // Calculate damage and armour for player's.
    if (currentArmour >= damage)
    {
        currentArmour = currentArmour - damage;

        std::cout << name << "'s armour has protected their health but taken " << damage << " damage. Remaining Armour: " << currentArmour << "\n";
        sleep(1);
    }

    // no armour, health takes all the damage
    else if (currentArmour <= 0)
    {
        currentHealth = currentHealth - damage;
        std::cout << name << "'s armour is depleted, their health has taken " << damage << " damage. Remaining Health: " << currentHealth << "\n";
        sleep(1);
    }

    // armour and health take damage
    else if (currentArmour > 0)
    {
        int remainingDamage = damage - currentArmour;
        currentArmour = 0;
        currentHealth = currentHealth - remainingDamage;
        std::cout << name << "'s armour was depleted by the attack, their health has taken " << remainingDamage << " damage. Remaining Health: " << currentHealth << "\n";
        sleep(1);
    };
};

/*void Mob::displayMap()
{
    Mat image = imread("map.jpg", IMREAD_GRAYSCALE);
    imshow("Map", image);
    waitKey(0);
}*/

void Mob::fight(Mob &target_player, Mob &target_boss)
{
    // cast target_boss from Mob to Boss, in order to access getDeathMessage().
    Boss target_boss_casted;
    try
    {
        // Verify that Mob pointer is a Boss
        target_boss_casted = dynamic_cast<Boss &>(target_boss);
        // If we reach this point, target_boss is a valid Boss object
        // You can use 'boss' safely in this block.
    }
    catch (const std::bad_cast &)
    {
        std::cout << "fight(Mob& target) was passed a non-Boss type" << std::endl;
        exit(1);
    }

    // cast target_player from Mob to Player, in order to access printInventory().
    Player target_player_casted;
    try
    {
        // Verify that Mob pointer is a Boss
        target_player_casted = dynamic_cast<Player &>(target_player);
        // If we reach this point, target_boss is a valid Boss object
        // You can use 'boss' safely in this block.
    }
    catch (const std::bad_cast &)
    {
        std::cout << "fight(Mob& target) was passed a non-Player type" << std::endl;
        exit(1);
    }

    bool bossAlive = true;
    bool playerAlive = true;

    sleep(1);

    while (bossAlive == true && playerAlive == true)
    {
        logger.print_bold("\n-> PROMPT: Enter [A]ttack or [I]nventory: ");
        char choice;
        std::cin >> choice;
        sleep(1);
        std::cout << "\n";
        if (choice == 'A' || choice == 'a')
        {
            // player attacks boss
            if (bossAlive == true)
            {
                attack(target_boss);
                if (!(target_boss.getCurrentHealth() > 0))
                {
                    std::cout << target_boss_casted.getDeathMessage() << std::endl;
                    std::cout << target_boss.getName() << " is slain." << std::endl;
                    killCounter++;
                    bossAlive = false;
                    return;
                }
            }
            sleep(1);

            // boss attacks player
            if (playerAlive == true)
            {
                target_boss.attack(*this);
                if (!(target_player.getCurrentHealth() > 0))
                {
                    std::cout << "You died!\n";
                    sleep(1);
                    exit(0);
                }
            }
        }
        else if (choice == 'I' || choice == 'i')
        {
            target_player_casted.printInventory();
        }
    }
}