#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"
#include "gamehistory.h"
#include "playerdbt.h"
#include "dbtool.h"
#include "dbtable.h"
#include <vector>
#include "playergamehistory.h"

class Game; // forward declaration when game.h is included

class GameHistory;

class PlayerGameHistory;

class Player
{
    int id;

    /**
     * @brief fn First name
     */
    char * fn;

    /**
     * @brief ln Last name
     */
    char * ln;

    /**
     * @brief ad Address
     */
    char * ad;

    /**
     * @brief ga Game that player played
     */
    Game * ga;

    /**
     * @brief gh Game history for specific player
     */
    GameHistory* gh;

    DBTool * dbtool;
    // BIG ISSUE: It's coming up as unknown type. Unsure why. It works in every other class it's included in!

public:

    /**
     * @brief Player Empty Constuctor
     */
    Player();

    /**
     * @brief Player Constructor to fill instance variables
     * @param g Game
     * @param f First name
     * @param l Last name
     * @param a Address
     */
    Player(Game *g, char * f, char * l, char * a);
    Player(char * f, char * l, char * a);
    Player(int iD, DBTool * dbt_pass, PlayerGameHistory* pgh);
    //Destructor
    ~Player();

    /**
     * @brief getFirstName Gets first name
     * @return First name
     */
    char * getFirstName();

    /**
     * @brief getLastName Gets last name
     * @return Last name
     */
    char * getLastName();

    /**
     * @brief getAddress Gets address
     * @return Address
     */
    char * getAddress();

    /**
     * @brief getGame Gets game
     * @return Game
     */
    Game * getGame();

    /**
     * @brief getGameHistory Gets Game History
     * @return Game History
     */
    GameHistory * getGameHistory();

    /**
     * @brief addToGameHistory Add to game history
     * @param g game to add
     */
    void addToGameHistory(Game * g);

    void addGame(Game * g);

    int getID();

    void save(DBTool * dbt_passed);
};

#endif // PLAYER_H
