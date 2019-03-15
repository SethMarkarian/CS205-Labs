#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H

#include "player.h"
#include "game.h"
#include "dbtool.h"
#include "dbtable.h"
#include "gamehistorydbt.h"
#include <vector>
#include <cstring>
#include "playergamehistory.h"

class Game;

class Player;

class PlayerGameHistory;

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

    int id;

    std::vector<std::string> string_to_vector(std::string str);
public:

    /**
     * @brief GameHistory Empty Constuctor
     */
    GameHistory();
    GameHistory(Player * pl);
    GameHistory(int iD, DBTool * dbt_pass, Player* p, PlayerGameHistory * pgh);

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

    int getID();

    Game * last_game();

    void save(DBTool * dbt_passed);

};

#endif // GAMEHISTORY_H
