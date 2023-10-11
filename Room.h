#ifndef ROOM_H
#define ROOM_H
#include <vector>

#include "Item.h"
#include "Player.h"

class Room {
    private:
        std::vector<Item*> items;
        std::vector<Boss*> bosses;

    public:
        Room();
    
    void enterRoom(Player& player);

    void addBoss(Boss* boss);
    void addItem(Item* item);

    Boss* getBoss(int index);
    Item* getItem(int index);

    int bossCount();
    int itemCount();
};
#endif // ROOM_H