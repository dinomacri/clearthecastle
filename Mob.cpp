#include "Mob.h"
#include <iostream>
#include <string>

#include "Boss.h"

// #include <windows.h> for windows clients. 
#include <unistd.h>

// its  getters and setters
int Mob::getBaseHealth()
{
    return baseHealth;
};

int Mob::getCurrentHealth()
{
    return currentHealth;
}

void Mob::setCurrentHealth(int newHealth)
{
    currentHealth = newHealth;
}

int Mob::getBaseArmour()
{
    return baseArmour;
};

int Mob::getCurrentArmour()
{
    return currentArmour;
}

void Mob::setCurrentArmour(int newArmour)
{
    currentArmour = newArmour;
}

int Mob::getBaseDamage()
{
    return baseDamage;
};

void Mob::takeDamage(int damage)
{
    std::cout << currentArmour << " " << damage << "\n";
     if (currentArmour >= damage)
    {
        currentArmour =  currentArmour - damage;
        
        std::cout << name << "'s Armour has protected their health but taken " << damage << " damage. Remaining Armour: " << currentArmour << "\n";
    }

    // no armour, health takes all the damage
    else if (currentArmour <= 0)
    {
         currentHealth = currentHealth -  damage;
        std::cout << name << "'s Armour is depleted, their health has taken " << damage << " damage. Remaining Health: " << currentHealth << "\n";
    };

    //armour and health take damage
    if ((currentArmour < damage) && (currentArmour > 0))
    {
        int A = currentArmour - damage;
        currentHealth = currentHealth + A;
        currentArmour = 0;
        std::cout << name << "'s Armour was depleted by the attack, their health has taken " << -A << " damage. Remaining Health: " << currentHealth << "\n";
    };
};

void Mob::fight(Mob& target_player, Mob& target_boss)
{
    // cast target_boss from Mob to Boss, in order to access getDeathMessage().
    Boss target_boss_casted;
    try {
        // Verify that Mob pointer is a Boss
        target_boss_casted = dynamic_cast<Boss&>(target_boss);
        // If we reach this point, target_boss is a valid Boss object
        // You can use 'boss' safely in this block.
    } catch (const std::bad_cast&) {
        std::cout << "fight(Mob& target) was passed a non-Boss type" << std::endl;
        exit(1);
    }

    bool bossAlive = true;
    bool playerAlive = true;
    
    sleep(1);

    while (bossAlive == true && playerAlive==true)
    {
        // player attacks boss
        if (bossAlive == true)
        {
            attack(target_boss);
            if (!(target_boss.getCurrentHealth() > 0))
            {
                std::cout << target_boss_casted.getDeathMessage() << std::endl;
                std::cout << target_boss.getName() << " is slain." << std::endl;
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
                std::cout << "You died!" << std::endl;
                sleep(1);
                exit(0);
            }
        }
    }
}