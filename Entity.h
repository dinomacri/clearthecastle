#ifndef ENTITY_H
#define ENTITY_H
#include <string>
// header for the entity
class Entity
{
    protected: // protected because it's easier to access
    std::string name;
    int location[2]; // location is a vector, with x y coords

    public:
    std::string getName();
    int* getLocation();
    void updateLocation(int newX, int newY);
};

#endif // ENTITY_H
