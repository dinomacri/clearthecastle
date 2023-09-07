#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
    private:
        std::string name;
        int health;
    public:
        Player();
        Player(std::string name, int health);

        std::string get_name();
        int get_health();
};

#endif //PLAYER_H