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

std::vector<Player *> PlayerGameHistory::top_3()
{
    std::vector<Player *> temp = players;
    std::vector<Player *> ret;
    for(int i = 0; i < 3 && i < players.size(); i++)
    {
        int id = 0;
        int max_avg = -1;
        for(int j = 0; j < temp.size(); j++)
        {
            int now_avg = avgScoreForPlayer(*temp[j]); // should try to test this??
            if(now_avg > max_avg)
            {
                id = j;
                max_avg = now_avg;
            }
        }
        ret.push_back(temp[id]);
        temp.erase(temp.begin() + id);
    }
    return ret;
}

std::vector<Game *> PlayerGameHistory::top_3_games()
{
    std::vector<Game *> temp = games;
    std::vector<Game *> ret;
    for(int i = 0; i < 3 && i < games.size(); i++)
    {
        int id = 0;
        int max_avg = -1;
        for(int j = 0; j < temp.size(); j++)
        {
            int now_avg = temp[j]->getFinalScore(); // should try to test this??
            if(now_avg > max_avg)
            {
                id = j;
                max_avg = now_avg;
            }
        }
        ret.push_back(temp[id]);
        temp.erase(temp.begin() + id);
    }
    return ret;
}

std::vector<Player *> PlayerGameHistory::retPlayers()
{
    return players;
}
