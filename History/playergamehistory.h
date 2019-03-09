#ifndef PLAYERGAMEHISTORY_H
#define PLAYERGAMEHISTORY_H

#include <vector>
#include "player.h"


class PlayerGameHistory
{
    /**
     * @brief players Vector of players
     */
    std::vector<Player *> players;

    /**
     * @brief games Vector of games
     */
    std::vector<Game *> games;
public:

    /**
     * @brief PlayerGameHistory Empty Constructor
     */
    PlayerGameHistory();

    //Destructor
    ~PlayerGameHistory();

    /**
     * @brief addPlayer Adds player to player vector
     * @param p Player to be added
     */
    void addPlayer(Player *p);

    /**
     * @brief addGame Adds game to game vector
     * @param g Game to be added
     */
    void addGame(Game *g);

    /**
     * @brief numGamesPlayed Number of times games have been played
     * @return number of games played
     */
    int numGamesPlayed();

    /**
     * @brief numPlayers Number of players
     * @return Number of players
     */
    int numPlayers();

    /**
     * @brief avgGamesPerPlayer Average number of games per player
     * @return Average number of games per player
     */
    int avgGamesPerPlayer();

    /**
     * @brief topScore Top score from all players
     * @return Top score
     */
    int topScore();

    /**
     * @brief avgScore Average score
     * @return Average score
     */
    int avgScore();

    /**
     * @brief avgScoreForPlayer Average score for one player
     * @param p Player
     * @return Average Score for one player
     */
    int avgScoreForPlayer(Player p);

    /**
     * @brief retPlayers returns a vector of the Player * 's in players
     * @return a vector of the Player * 's in players
     */
    std::vector<Player *> top_3();
    std::vector<Game *> top_3_games();
    std::vector<Player *> retPlayers();
};

#endif // PLAYERGAMEHISTORY_H
