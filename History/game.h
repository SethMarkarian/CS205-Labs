#ifndef GAME_H
#define GAME_H
#include "player.h"

class Player;

class Game
{
    Player * pl;
public:
    Game();
    Game(Player *p);
    ~Game();
};

#endif // GAME_H
