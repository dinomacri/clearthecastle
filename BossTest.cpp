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

    // Print the armour to the console
    std::cout << greg.getBaseArmour() << std::endl;

    return 0;
}