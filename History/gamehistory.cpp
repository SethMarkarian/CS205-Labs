#include "gamehistory.h"

GameHistory::GameHistory()
{

}

void GameHistory::addGame(Game *g) {
    games.push_back(g);
}
