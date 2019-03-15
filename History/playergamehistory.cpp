#include "playergamehistory.h"

/**
 * @brief PlayerGameHistory Empty Constructor
 */
PlayerGameHistory::PlayerGameHistory()
{

}

PlayerGameHistory::PlayerGameHistory(std::string DBName)
{
    // create DBTool
    DBN = DBName;
    char * dbtc = (char *) DBN.c_str();
    DBTool * dbt = new DBTool(dbtc);
    // create PGHDBT
    PlayerGameHistoryDBT * pghdbt = new PlayerGameHistoryDBT(dbt, "PGHTable");
    // initialize vectors
    std::vector<std::string> col_strings = pghdbt->ret_pgh(0);
    std::vector<std::string> player_strings = string_to_vector(col_strings [1]);
    std::vector<std::string> game_strings = string_to_vector(col_strings[2]);
    // fill in the games vector with nullptrs so it is the right size
    for(int i = 0; i < game_strings.size(); i++){
        games.push_back(nullptr);
        // note: the Game * 's get added in GameHistory
    }
    // create players based on ID numbers
    for(int i = 0; i < player_strings.size(); i++){
        int id_n = atoi(player_strings[i].c_str());
        Player* p = new Player(id_n, dbt, this);
        players.push_back(p);
    }
    // delete stuff
    delete pghdbt;
    delete dbt;
}

//Destructor
PlayerGameHistory::~PlayerGameHistory() {
    // need all the other objects to save :)
    // create dbt
    char * dbtc = (char *) DBN.c_str();
    DBTool * dbt = new DBTool(dbtc);
    // delete old data from tables
    PlayerGameHistoryDBT * pghdbt = new PlayerGameHistoryDBT(dbt, "PGHTable");
    pghdbt->del_rows();
    GameDBT * gdbt = new GameDBT(dbt, "GTable");
    gdbt->del_rows();
    delete gdbt;
    PlayerDBT * pdbt = new PlayerDBT(dbt, "PTable");
    pdbt->del_rows();
    delete pdbt;
    GameHistoryDBT * ghdbt = new GameHistoryDBT(dbt, "GHTable");
    ghdbt->del_rows();
    delete ghdbt;
    // create strings to hold Player ids and Game ids
    std::string pl_ids;
    std::string g_ids;
    if(players.size() > 0)
    {
        // first player id is separated out for formatting
        pl_ids = std::to_string(players[0]->getID());
        players[0]->save(dbt);
    }
    for(int i = 1; i < players.size(); i++){
        // instruct each player to save
        players[i]->save(dbt);
        // add their id to the string
        pl_ids += ",";
        pl_ids += std::to_string(players[i]->getID());
    }
    if(games.size() > 0)
    {
        // first game id is separated out for formatting
        g_ids = std::to_string(games[0]->getID());
    }
    for(int i = 1; i < games.size(); i++){
        // add each game's id to the string
        g_ids += ",";
        g_ids += std::to_string(games[i]->getID());
    }
    // save the data to the table
    pghdbt->add_row(0, pl_ids, g_ids);
    // delete as necessary
    delete pghdbt;
    delete dbt;
}

/**
 * @brief addPlayer Adds player to player vector
 * @param p Player to be added
 */
void PlayerGameHistory::addPlayer(Player * p) {
    players.push_back(p);
}

/**
 * @brief addGame Adds game to game vector
 * @param g Game to be added
 */
void PlayerGameHistory::addGame(Game * g) {
    games.push_back(g);
}

/**
 * @brief numGamesPlayed Number of times games have been played
 * @return number of games played
 */
int PlayerGameHistory::numGamesPlayed() {
    return games.size();
}

/**
 * @brief numPlayers Number of players
 * @return Number of players
 */
int PlayerGameHistory::numPlayers() {
    return players.size();
}

/**
 * @brief avgGamesPerPlayer Average number of games per player
 * @return Average number of games per player
 */
int PlayerGameHistory::avgGamesPerPlayer() {
    int total = 0;
    for(int i = 0; i < players.size(); i++) {
        total += players[i]->getGameHistory()->getTotalGames();
    }
    return total / players.size();
}

/**
 * @brief topScore Top score from all players
 * @return Top score
 */
int PlayerGameHistory::topScore() {
    int max = -1;
    for(int i = 0; i < games.size(); i++) {
        if(games[i]->getFinalScore() > max) {
            max = games[i]->getFinalScore();
        }
    }
    return max;
}

/**
 * @brief avgScore Average score
 * @return Average score
 */
int PlayerGameHistory::avgScore() {
    int total = 0;
    for(int i = 0; i < games.size(); i++) {
       total += games[i]->getFinalScore();
    }
    return total / games.size();
}

/**
 * @brief avgScoreForPlayer Average score for one player
 * @param p Player
 * @return Average Score for one player
 */
int PlayerGameHistory::avgScoreForPlayer(Player p) {
    int total = 0;
    for(int i = 0; i < p.getGameHistory()->getTotalGames(); i++) {
        total += p.getGameHistory()->getGame(i)->getFinalScore();
    }
    return total / p.getGameHistory()->getTotalGames();
}

std::vector<Player *> PlayerGameHistory::top_3()
{
    std::vector<Player *> temp = players;
    std::vector<Player *> ret;
    for(int i = 0; i < 3 && i < players.size(); i++)
    {
        int id = 0;
        int max_avg = -1;
        for(int j = 0; j < temp.size(); j++)
        {
            int now_avg = avgScoreForPlayer(*temp[j]); // should try to test this??
            if(now_avg > max_avg)
            {
                id = j;
                max_avg = now_avg;
            }
        }
        ret.push_back(temp[id]);
        temp.erase(temp.begin() + id);
    }
    return ret;
}

std::vector<Game *> PlayerGameHistory::top_3_games()
{
    std::vector<Game *> temp = games;
    std::vector<Game *> ret;
    for(int i = 0; i < 3 && i < games.size(); i++)
    {
        int id = 0;
        int max_avg = -1;
        for(int j = 0; j < temp.size(); j++)
        {
            int now_avg = temp[j]->getFinalScore(); // should try to test this??
            if(now_avg > max_avg)
            {
                id = j;
                max_avg = now_avg;
            }
        }
        ret.push_back(temp[id]);
        temp.erase(temp.begin() + id);
    }
    return ret;
}

std::vector<Player *> PlayerGameHistory::retPlayers()
{
    return players;
}

std::vector<std::string> PlayerGameHistory::string_to_vector(std::string str){
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

void PlayerGameHistory::insert_game(Game *g, int i){
    std::vector<Game *>::iterator it = games.begin();
    games.insert(it + i, g);
}

std::string PlayerGameHistory::vec_to_string(std::vector<int> ints){
    std::string temp;
    if(ints.size() > 0)
    {
        temp += std::to_string(ints[0]);
    }
    for(int i = 1; i < ints.size(); i++){
        temp += ",";
        temp += std::to_string(ints[i]);
    }
    return temp;
}
