#include "playergamehistory.h"

PlayerGameHistory::PlayerGameHistory()
{

}

void PlayerGameHistory::addPlayer(Player p) {
    players.push_back(p);
}

void PlayerGameHistory::addGame(Game g) {
    games.push_back(g);
}

int PlayerGameHistory::numGamesPlayed() {
    return games.size();
}

int PlayerGameHistory::numPlayers() {
    return players.size();
}

int PlayerGameHistory::avgGamesPerPlayer(Player p) {
    return 0; //Insert method from game history class
}

int PlayerGameHistory::topScore() {
    //loop over players to find top score for a specific game
    return 0;
}

int PlayerGameHistory::avgScore() {
    //find average for all games
    return 0;
}

int PlayerGameHistory::avgScoreForPlayer(Player p) {
    //find average score for a specific player
    return 0;
}
