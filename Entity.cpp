#include "Entity.h"
#include <iostream>
#include <string>

std::string Entity::getName()
{
    return name;
};

int* Entity::getLocation()
{
    return location;
}
void Entity::updateLocation(int newX, int newY)
{
    location[0] = newX;
    location[1] = newY;
};
