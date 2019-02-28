#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include <player.h>
#include <vector>

class GameHistory
{
    Player * pl;
    std::vector<Game> games;

public:
    GameHistory();
    void addGame(Game g);

};

#endif // GAMEHISTORY_H
