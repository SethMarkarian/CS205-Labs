#ifndef PLAYER_H
#define PLAYER_H
#include "game.h"

class Game; // forward declaration when game.h is included

class Player
{
    char * fn; // stands for first name
    char * ln; // stands for last name
    char * ad; // stands for address
    Game * ga;

public:
    Player();
    Player(Game *g);
    ~Player();
};

#endif // PLAYER_H
