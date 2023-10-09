#include "Boss.h"
#include "Mob.h"

#include <iostream>
#include <string>

int main()
{
    std::cout<< "Test Boss" << std::endl;
    Boss Greg("Greg", 1, 1, 10, 3, 4, "Greg fucken died", "Club");
    std::string DeathMessage = Greg.getDeathMessage(); // Get the armour bonus

    // Print the armour bonus to the console
    std::cout << DeathMessage << std::endl;



    return 0;
}