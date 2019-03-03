#include "gamehistory.h"

GameHistory::GameHistory()
{

}

void GameHistory::addGame(Game *g) {
    games.push_back(g);
}

Player * GameHistory::getPlayer() {
    return pl;
}

int GameHistory::getTotalGames() {
    return games.size();
}

Game * GameHistory::getGame(int i) {
    return games[i];
}
