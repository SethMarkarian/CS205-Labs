#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <player.h>
#include <vector>

class GameHistory
{
    Player * pl;


public:
    std::vector<Game *> games;
    GameHistory();
    void addGame(Game *g);

};

#endif // GAMEHISTORY_H
