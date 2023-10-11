#ifndef ENTITY_H
#define ENTITY_H
#include <string>
// header for the entity
class Entity
{
    protected: // protected because it's easier to access
    std::string name;

    public:
    std::string getName();
};

#endif // ENTITY_H
