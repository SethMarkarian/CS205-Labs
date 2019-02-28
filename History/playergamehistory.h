#ifndef PLAYERGAMEHISTORY_H
#define PLAYERGAMEHISTORY_H

#include <vector>
#include <player.h>


class PlayerGameHistory
{
    std::vector<Player> players;
    std::vector<Game> games;
public:
    PlayerGameHistory();
    void addPlayer(Player p);
    void addGame(Game g);
    int numGamesPlayed();
    int numPlayers();
    int avgGamesPerPlayer(Player p);
    int topScore();
    int avgScore();
    int avgScoreForPlayer(Player p);
};

#endif // PLAYERGAMEHISTORY_H
