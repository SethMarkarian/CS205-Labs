#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "gamedbt.h"
#include "dbtool.h"

class Player;

class Game
{
    /**
     * @brief pl Player that played the game
     */
    Player * pl;

    /**
     * @brief name Name of the game played
     */
    char * name;

    /**
     * @brief fs Final Score
     */
    int fs; //final score

    /**
     * @brief id id on table row
     */
    int id;
public:

    /**
     * @brief Game Empty Constructor
     */
    Game();

    /**
     * @brief Game Constructor to add to the instance variables
     * @param p Player
     * @param n Name of game
     * @param f final score
     */
    Game(Player *p, char * n, int f);

    /**
     * @brief Game Constructor to load from database table
     * @param p this game's Player
     * @param iD id of row on table
     * @param dbtpass Database Tool
     */
    Game(Player *p, int iD, DBTool * dbtpass);


    ~Game(); //Destructor

    /**
     * @brief getPlayer Gets player
     * @return Specific player object
     */
    Player getPlayer();

    /**
     * @brief getName Gets name of game
     * @return Name of game
     */
    char * getName();

    /**
     * @brief getFinalScore Gets final score of game played
     * @return final score
     */
    int getFinalScore();

    void setFinalScore(int i);

    /**
     * @brief getID returns id
     * @return int id
     */
    int getID();

    /**
     * @brief print_game prints the name of the game
     */
    void print_game();

    /**
     * @brief save saves this data to the table
     * @param dbt_passed DBTool to use
     */
    void save(DBTool *dbt_passed);
};

#endif // GAME_H
