#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include "player.h"
#include "game.h"
#include <vector>

class Game;

class Player;

class GameHistory
{
    /**
     * @brief pl Player
     */
    Player * pl;

    /**
     * @brief games Vector of Games
     */
    std::vector<Game*> games;

public:

    /**
     * @brief GameHistory Empty Constuctor
     */
    GameHistory();

    /**
     * @brief addGame Adds game to vector fo games
     * @param g Game to be added
     */
    void addGame(Game* g);

    /**
     * @brief getPlayer Gets player from instance variable
     * @return Player instance variable
     */
    Player* getPlayer();

    /**
     * @brief getTotalGames Gets number of games played
     * @return Number of games played
     */
    int getTotalGames();

    /**
     * @brief getGame Get game at an interval
     * @param i Interval
     * @return Game at ith place
     */
    Game* getGame(int i);


};

#endif // GAMEHISTORY_H
