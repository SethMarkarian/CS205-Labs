#include "gamehistory.h"

/**
 * @brief GameHistory Empty Constuctor
 */
GameHistory::GameHistory()
{

}

/**
 * @brief addGame Adds game to vector fo games
 * @param g Game to be added
 */
void GameHistory::addGame(Game *g) {
    games.push_back(g);
}

/**
 * @brief getPlayer Gets player from instance variable
 * @return Player instance variable
 */
Player * GameHistory::getPlayer() {
    return pl;
}

/**
 * @brief getTotalGames Gets number of games played
 * @return Number of games played
 */
int GameHistory::getTotalGames() {
    return games.size();
}

/**
 * @brief getGame Get game at an interval
 * @param i Interval
 * @return Game at ith place
 */
Game * GameHistory::getGame(int i) {
    return games[i];
}
