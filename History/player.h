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
    /**
     * @brief id id on table row
     */
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
    // BIG ISSUE: It's coming up as unknown type. Unsure why
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
    /**
     * @brief Player Constructor to load from database table
     * @param iD of row on table
     * @param dbt_pass Database Tool
     * @param pgh PlayerGameHistory calling this
     */
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

    /**
     * @brief addGame changes this player's most recently played game
     * @param g
     */
    void addGame(Game * g);

    /**
     * @brief getID return this player's ID
     * @return int id
     */
    int getID();

    /**
     * @brief save saves this player's data to the table
     * @param dbt_passed DBTool to use
     */
    void save(DBTool * dbt_passed);
};

#endif // PLAYER_H
