#ifndef GAME_H
#define GAME_H

#include "player.h"

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
};

#endif // GAME_H
