#include "player.h"
#include "game.h"

Player::Player()
{

}

Player::Player(Game *g, char * f, char * l, char * a)
{
    ga = g;
    fn = f;
    ln = l;
    ad = a;
    gh = new GameHistory();
}

Player::~Player() {

}

char * Player::getFirstName() {
    return fn;
}

char * Player::getLastName() {
    return ln;
}

char * Player::getAddress() {
    return ad;
}

Game * Player::getGame() {
    return ga;
}

GameHistory * Player::getGameHistory() {
    return gh;
}

void Player::addToGameHistory(Game * g) {
    gh->addGame(g);
}
