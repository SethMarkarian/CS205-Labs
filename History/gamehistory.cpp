#include "gamehistory.h"

/**
 * @brief GameHistory Empty Constuctor
 */
GameHistory::GameHistory()
{
    id = -1; // to be changed when saved
}

GameHistory::GameHistory(int iD, DBTool * dbt_pass, Player * p, PlayerGameHistory* pgh)
{
    id = iD;
    pl = p;
    GameHistoryDBT * ghdbt = new GameHistoryDBT(dbt_pass, "GHTable");
    std::vector<std::string> vals = ghdbt->ret_gh(iD);
    std::vector<std::string> g_ids_str = string_to_vector(vals[2]);
    for(int i = 0; i < g_ids_str.size(); i++)
    {
        int curr_id = atoi(g_ids_str[i].c_str());
        Game * curr_game = new Game(p, curr_id, dbt_pass);
        games.push_back(curr_game);
        pgh->insert_game(curr_game, curr_id);
    }
    delete ghdbt;
}

/**
 * @brief addGame Adds game to vector fo games
 * @param g Game to be added
 */
void GameHistory::addGame(Game *g) {
    games.push_back(g);
}

/**
 * @brief getPlayer Gets player from instance variable
 * @return Player instance variable
 */
Player * GameHistory::getPlayer() {
    return pl;
}

/**
 * @brief getTotalGames Gets number of games played
 * @return Number of games played
 */
int GameHistory::getTotalGames() {
    return games.size();
}

/**
 * @brief getGame Get game at an interval
 * @param i Interval
 * @return Game at ith place
 */
Game * GameHistory::getGame(int i) {
    return games[i];
}

int GameHistory::getID(){
    return id;
}

std::vector<std::string> GameHistory::string_to_vector(std::string str){
    std::vector<std::string> temp;
    char * checker;
    checker = strchr((char*)str.c_str(), ',');
    if(checker != NULL)
    {
        char * curr = strtok((char*)str.c_str(), ",");
        temp.push_back(curr);
    }
    while(checker != NULL)
    {
        char * curr = strtok(NULL, ",");
        temp.push_back(curr);
    }
    return temp;
}

Game * GameHistory::last_game(){
    return games[games.size()-1];
}

void GameHistory::save(DBTool *dbt_passed){
    GameHistoryDBT * ghdbt = new GameHistoryDBT(dbt_passed, "GHTable");
    if(id == -1)
    {
        id = ghdbt->num_rows();
    }
    std::string g_ids;
    if(games.size() > 0)
    {
        g_ids = std::to_string(games[0]->getID());
        games[0]->save(dbt_passed);
    }
    for(int i = 1; i < games.size(); i++){
        g_ids += ",";
        g_ids += std::to_string(games[i]->getID());
        games[i]->save(dbt_passed);
    }
    ghdbt->add_row(id, pl->getID(), g_ids);
    delete ghdbt;
}
