#include "playergamehistory.h"

/**
 * @brief PlayerGameHistory Empty Constructor
 */
PlayerGameHistory::PlayerGameHistory()
{

}

//Destructor
PlayerGameHistory::~PlayerGameHistory() {

}

/**
 * @brief addPlayer Adds player to player vector
 * @param p Player to be added
 */
void PlayerGameHistory::addPlayer(Player * p) {
    players.push_back(p);
}

/**
 * @brief addGame Adds game to game vector
 * @param g Game to be added
 */
void PlayerGameHistory::addGame(Game * g) {
    games.push_back(g);
}

/**
 * @brief numGamesPlayed Number of times games have been played
 * @return number of games played
 */
int PlayerGameHistory::numGamesPlayed() {
    return games.size();
}

/**
 * @brief numPlayers Number of players
 * @return Number of players
 */
int PlayerGameHistory::numPlayers() {
    return players.size();
}

/**
 * @brief avgGamesPerPlayer Average number of games per player
 * @return Average number of games per player
 */
int PlayerGameHistory::avgGamesPerPlayer() {
    int total = 0;
    for(int i = 0; i < players.size(); i++) {
        total += players[i]->getGameHistory()->getTotalGames();
    }
    return total / players.size();
}

/**
 * @brief topScore Top score from all players
 * @return Top score
 */
int PlayerGameHistory::topScore() {
    int max = -1;
    for(int i = 0; i < games.size(); i++) {
        if(games[i]->getFinalScore() > max) {
            max = games[i]->getFinalScore();
        }
    }
    return max;
}

/**
 * @brief avgScore Average score
 * @return Average score
 */
int PlayerGameHistory::avgScore() {
    int total = 0;
    for(int i = 0; i < games.size(); i++) {
       total += games[i]->getFinalScore();
    }
    return total / games.size();
}

/**
 * @brief avgScoreForPlayer Average score for one player
 * @param p Player
 * @return Average Score for one player
 */
int PlayerGameHistory::avgScoreForPlayer(Player p) {
    int total = 0;
    for(int i = 0; i < p.getGameHistory()->getTotalGames(); i++) {
        total += p.getGameHistory()->getGame(i)->getFinalScore();
    }
    return total / p.getGameHistory()->getTotalGames();
}

std::vector<Player *> PlayerGameHistory::retPlayers()
{
    return players;
}
