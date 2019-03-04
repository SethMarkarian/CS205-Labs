#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"
#include "gamehistory.h"

class Game; // forward declaration when game.h is included

class GameHistory;

class Player
{
    char * fn; // stands for first name
    char * ln; // stands for last name
    char * ad; // stands for address
    Game * ga;
    GameHistory* gh;

public:
    Player();
    Player(Game *g, char * f, char * l, char * a);
    ~Player();

    char * getFirstName(); //all gets
    char * getLastName();
    char * getAddress();
    Game * getGame();
    GameHistory * getGameHistory();
    void addToGameHistory(Game * g);
};

#endif // PLAYER_H
