#include "player.h"
#include "game.h"

Player::Player()
{
    gh = new GameHistory();
}

Player::Player(Game *g)
{
    ga = g;
    gh = new GameHistory();
}

Player::~Player() {

}

void Player::setFirstName(char *f) {
    fn = f;
}

void Player::setLastName(char *l) {
    ln = l;
}

void Player::setAddress(char *a) {
    ad = a;
}

void Player::addToGameHistory() {
    gh->addGame(ga);
}
