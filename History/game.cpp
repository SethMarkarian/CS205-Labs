#include "game.h"

/**
 * @brief Game Empty Constructor
 */
Game::Game()
{

}

/**
 * @brief Game Constructor to add to the instance variables
 * @param p Player
 * @param n Name of game
 * @param f final score
 */
Game::Game(Player *p, char * n, int f)
{
    pl = p;
    name = n;
    fs = f;
}

//Destructor
Game::~Game() {

}

/**
 * @brief getPlayer Gets player
 * @return Specific player object
 */
Player Game::getPlayer() {
    return *pl;
}

/**
 * @brief getName Gets name of game
 * @return Name of game
 */
char * Game::getName() {
    return name;
}

/**
 * @brief getFinalScore Gets final score of game played
 * @return final score
 */
int Game::getFinalScore() {
    return fs;
}
