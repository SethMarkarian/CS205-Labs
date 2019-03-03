#include "playergamehistory.h"

PlayerGameHistory::PlayerGameHistory()
{

}

PlayerGameHistory::~PlayerGameHistory() {

}

void PlayerGameHistory::addPlayer(Player * p) {
    players.push_back(p);
}

void PlayerGameHistory::addGame(Game * g) {
    games.push_back(g);
}

int PlayerGameHistory::numGamesPlayed() {
    return games.size();
}

int PlayerGameHistory::numPlayers() {
    return players.size();
}

int PlayerGameHistory::avgGamesPerPlayer() {
    int total = 0;
    for(int i = 0; i < players.size(); i++) {
        total += players[i]->getGameHistory()->getTotalGames();
    }
    return total / players.size();
}

int PlayerGameHistory::topScore() {
    int max = -1;
    for(int i = 0; i < games.size(); i++) {
        if(games[i]->getFinalScore() > max) {
            max = games[i]->getFinalScore();
        }
    }
    return max;
}

int PlayerGameHistory::avgScore() {
    int total = 0;
    for(int i = 0; i < games.size(); i++) {
       total += games[i]->getFinalScore();
    }
    return total / games.size();
}

int PlayerGameHistory::avgScoreForPlayer(Player p) {
    int total = 0;
    for(int i = 0; i < p.getGameHistory()->getTotalGames(); i++) {
        total += p.getGameHistory()->getGame(i)->getFinalScore();
    }
    return total / p.getGameHistory()->getTotalGames();
}
