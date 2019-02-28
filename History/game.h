#ifndef GAME_H
#define GAME_H
#include "player.h"

class Player;

class Game
{
    Player * pl; //player that played the game
    char * name; //name of game
    int fs; //final score
public:
    Game();
    Game(Player *p);
    ~Game();
};

#endif // GAME_H
