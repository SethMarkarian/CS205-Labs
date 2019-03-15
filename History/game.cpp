#include "game.h"

/**
 * @brief Game Empty Constructor
 */
Game::Game()
{

}

/**
 * @brief Game Constructor to add to the instance variables
 * @param p Player
 * @param n Name of game
 * @param f final score
 */
Game::Game(Player *p, char * n, int f)
{
    pl = p;
    name = n;
    fs = f;
    id = -1; // going to fix in saving :)
}

Game::Game(Player *p, int iD, DBTool * dbtpass)
{
    // create gdbt
    GameDBT * gdbt = new GameDBT(dbtpass, "GTable");
    // get values from gdbt
    std::vector<std::string> vals = gdbt->ret_game(iD);
    // set id, pl, name, and fs
    id = iD;
    pl = p;
    name = (char*)vals[1].c_str();
    fs = atoi(vals[2].c_str());
    delete gdbt;
}

//Destructor
Game::~Game() {

}

void Game::print_game()
{
    std::cout << name;
}

int Game::getID()
{
    return id;
}

/**
 * @brief getPlayer Gets player
 * @return Specific player object
 */
Player Game::getPlayer() {
    return *pl;
}

/**
 * @brief getName Gets name of game
 * @return Name of game
 */
char * Game::getName() {
    return name;
}

/**
 * @brief getFinalScore Gets final score of game played
 * @return final score
 */
int Game::getFinalScore() {
    return fs;
}

void Game::setFinalScore(int i) {
    fs = i;
}

void Game::save(DBTool *dbt_passed){
    // create gdbt
    GameDBT * gdbt = new GameDBT(dbt_passed, "GTable");
    if(id == -1)
    {
        // set id if this game wasn't loaded from the table
        id = gdbt->num_rows();
    }
    // save data to table
    gdbt->add_row(id, name, fs, pl->getID());
    delete gdbt;
}
