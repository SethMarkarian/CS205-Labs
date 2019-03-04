#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include "player.h"
#include "game.h"
#include <vector>

class Game;

class Player;

class GameHistory
{
    Player * pl;
    std::vector<Game*> games;

public:
    GameHistory();
    void addGame(Game* g);
    Player* getPlayer();
    int getTotalGames();
    Game* getGame(int i);


};

#endif // GAMEHISTORY_H
