#include "gamedbt.h"

GameDBT::GameDBT()
{

}

GameDBT::GameDBT(DBTool* db, std::string name) : DBTable (db, name)
{
    // Load SQL specific to child class.
    // this stores a string used in create() in build_table in DBTable
    store_create_sql();
    store_template_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
}

GameDBT::~GameDBT(){

}

void GameDBT::print_game()
{
    for(int i = 0; i < curr_game.size(); i++){
        std::cout << curr_game[i] << " ";
    }
}

void GameDBT::set_game(std::vector<std::string> now_game)
{
    curr_game = now_game;
}

void GameDBT::set_num_rows(int n){
    n_rows = n;
}

void GameDBT::store_create_sql(){
    //std::cerr << "calling store_create_sql from DBTableEx\n";

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  gameName TEXT NOT NULL,";
    sql_create += "  finalScore INT  NOT NULL, ";
    sql_create += "  playerID INT  NOT NULL";
    sql_create += " );";
}

void GameDBT::store_template_sql(){
    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";
}

int GameDBT::num_rows(){
    get_num_rows();
    return n_rows;
}

bool GameDBT::del_rows(){

    int   retCode = 0;
    char *zErrMsg = 0;

    sql_del_rows = "DELETE FROM ";
    sql_del_rows += table_name;
    sql_del_rows += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_del_rows.c_str(),
                           cb_del_rows,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }
    return retCode;
}

bool GameDBT::add_row(int id, std::string gameName, int finalScore, int playerID)
{
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, gameName, finalScore, playerID ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(gameName);
    sql_add_row += "\", ";

    sprintf (tempval, "%d", finalScore);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%d", playerID);
    sql_add_row += tempval;
    // sql_add_row += ", ";

    sql_add_row += " );";

    //std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

std::vector<std::string> GameDBT::ret_game(int iD)
{
    get_row(iD);
    return curr_game;
}

bool GameDBT::get_num_rows(){

    int   retCode = 0;
    char *zErrMsg = 0;

    sql_get_num_rows = "SELECT count(*) FROM ";
    sql_get_num_rows += table_name;
    sql_get_num_rows += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_get_num_rows.c_str(),
                           cb_g_num_rows,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }
    return retCode;
}

bool GameDBT::get_row(int iD)
{

    int   retCode = 0;
    char *zErrMsg = 0;

    sql_get_row = "SELECT * FROM ";
    sql_get_row += table_name;
    sql_get_row += " WHERE id=";
    sql_get_row += std::to_string(iD);
    sql_get_row += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_get_row.c_str(),
                           cb_ret_game,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }
    return retCode;
}

bool GameDBT::select_all() {

    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all  = "SELECT * FROM ";
    sql_select_all += table_name;
    sql_select_all += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all.c_str(),
                           cb_select_all,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

int cb_ret_game (void  *data,
               int    argc,
               char **argv,
               char **azColName)
{



    std::cerr << "cb_ret_game being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    GameDBT *obj = (GameDBT *) data;

    std::vector<std::string> temp;

    for(i = 0; i < argc; i++)
    {
        temp.push_back(argv[i] ? argv[i] : "NULL");
    }

    obj->set_game(temp);

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                  << " = "
                  <<  (argv[i] ? std::string(argv[i]) : "NULL")
                  << std::endl;
    }
    return 0;
}

int cb_g_num_rows (void  *data,
               int    argc,
               char **argv,
               char **azColName)
{
    std::cerr << "cb_g_num_rows being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    GameDBT *obj = (GameDBT *) data;

    int temp = atoi(argv[0]);

    obj->set_num_rows(temp);

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(int i = 0; i < argc; i++){
        std::cout << azColName[i]
                  << " = "
                  <<  (argv[i] ? std::string(argv[i]) : "NULL")
                  << std::endl;
    }
    return 0;
}
int cb_del_rows (void  *data,
               int    argc,
               char **argv,
               char **azColName)
{
    std::cerr << "cb_del_rows being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    return 0;
}
