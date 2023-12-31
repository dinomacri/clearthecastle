#include <iostream>
#include <unistd.h>

#include "Room.h"
#include "Boss.h"
#include "Logger.h"

extern Logger logger;

Room::Room()
{
    Room("NULL");
}

Room::Room(std::string _name)
{
    name = _name;

    // initialise empty vectors
    items = std::vector<Item *>();
    bosses = std::vector<Boss *>();
}

Room::~Room()
{
    logger.print_debug("~Room() called: " + getName() + " was destroyed\n");
}

void Room::enterRoom(Player &player)
{
    logger.print_bold("You enter the next room.\n");
    sleep(1);

    // Check if boss in room
    if (this->bossCount() == 0)
    {
        logger.print_bold("You relax, as the room seems empty\n");
        sleep(1);
    }
    else
    {
        for (int i = 0; i < this->bossCount(); i++)
        {
            Mob *boss = this->getBoss(i);
            logger.print_bold("You see a boss. Get ready for a fight!\n");
            sleep(1);

            player.fight(player, *boss);
        }
        
        // clear the bosses from the room
        bosses.clear();
    }

    // Check if there are items in the room
    if (!items.empty())
    {
        for (int i = 0; i < this->itemCount(); i++)
        {
            logger.print_player("You find an item in the room. Do you want to pick it up? (y/n): ");
            char choice;
            std::cin >> choice;
            sleep(1);
            if (choice == 'Y' || choice == 'y')
            {
                player.equipItem(this->getItem(i));
                sleep(1);
            }
            else
            {
                logger.print_bold("You decide to leave the item alone\n");
                sleep(1);
            }
            // clear all items from the room
            items.clear();
        }
    }
}

void Room::addBoss(Boss *boss)
{
    bosses.push_back(boss);
}

void Room::addItem(Item *item)
{
    items.push_back(item);
}

Boss *Room::getBoss(int index)
{
    if (index >= 0 && index < static_cast<int>(bosses.size()))
    {
        return bosses[index];
    }
    return nullptr;
}

Item *Room::getItem(int index)
{
    if (index >= 0 && index < static_cast<int>(items.size()))
    {
        return items[index];
    }
    return nullptr;
}

int Room::bossCount()
{
    return bosses.size();
}

int Room::itemCount()
{
    return items.size();
}
