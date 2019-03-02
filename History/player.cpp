#include "player.h"
#include "game.h"

Player::Player()
{
    gh = GameHistory();
}

Player::Player(Game *g)
{
    gh = GameHistory();
}
