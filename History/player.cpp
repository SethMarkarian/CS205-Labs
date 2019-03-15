#include "player.h"
#include "game.h"


/**
 * @brief Player Empty Constuctor
 */
Player::Player()
{

}

Player::Player(int iD, DBTool * dbt_pass, PlayerGameHistory * pgh)
{
    // set id
    id = iD;
    // create pdbt
    PlayerDBT * pdbt = new PlayerDBT(dbtool, "PTable");
    // get values from pdbt
    std::vector<std::string> vals = pdbt->ret_p(id);
    // set instance variables
    fn = (char*) vals[1].c_str();
    ln = (char*) vals[2].c_str();
    ad = (char*) vals[3].c_str();
    // make the player's game history
    gh = new GameHistory(atoi(vals[5].c_str()), dbt_pass, this, pgh);
    // then, from game history, return the most recent game, which is this player's game
    ga = gh->last_game();
    delete pdbt;
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
    gh = new GameHistory(this);
    id = -1; // this will be changed when saving
}

Player::Player(char * f, char * l, char * a)
{
    fn = f;
    ln = l;
    ad = a;
    gh = new GameHistory(this);
    id = -1; // this will be changed when saving
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

int Player::getID(){
    return id;
}

void Player::save(DBTool *dbt_passed){
    // create pdbt
    std::string str = "PTable";
    PlayerDBT * pdbt = new PlayerDBT(dbt_passed, str);
    if(id == -1)
    {
        // set id if this was not loaded from the table before
        id = pdbt->num_rows();
    }
    // add row to PTable
    pdbt->add_row(id, fn, ln, ad, ga->getID(), gh->getID());
    // have the GameHistory save
    gh->save(dbt_passed);
    delete pdbt;
}
