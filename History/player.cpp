#include "player.h"
#include "game.h"

/**
 * @brief Player Empty Constuctor
 */
Player::Player()
{
    // need to have a constructor based on ID number
    // check if PDBT exists/ make one
    // load in data from table based on ID number; attributes here
    // create a new Game based on its id number
    // create a new GameHistory based on its id number, pass pointer
    // need to have global DBT and a constructor based on adding a new row
}

/**
 * @brief Player Constructor to fill instance variables
 * @param g Game
 * @param f First name
 * @param l Last name
 * @param a Address
 */
Player::Player(Game *g, char * f, char * l, char * a)
{
    ga = g;
    fn = f;
    ln = l;
    ad = a;
    gh = new GameHistory();
}

Player::Player(char * f, char * l, char * a)
{
    fn = f;
    ln = l;
    ad = a;
    gh = new GameHistory();
}

//Destructor
Player::~Player() {

}

/**
 * @brief getFirstName Gets first name
 * @return First name
 */
char * Player::getFirstName() {
    return fn;
}

/**
 * @brief getLastName Gets last name
 * @return Last name
 */
char * Player::getLastName() {
    return ln;
}

/**
 * @brief getAddress Gets address
 * @return Address
 */
char * Player::getAddress() {
    return ad;
}

/**
 * @brief getGame Gets game
 * @return Game
 */
Game * Player::getGame() {
    return ga;
}

/**
 * @brief getGameHistory Gets Game History
 * @return Game History
 */
GameHistory * Player::getGameHistory() {
    return gh;
}

/**
 * @brief addToGameHistory Add to game history
 * @param g game to add
 */
void Player::addToGameHistory(Game * g) {
    gh->addGame(g);
}

void Player::addGame(Game * g) {
    ga = g;
}
