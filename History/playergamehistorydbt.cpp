#include "playergamehistorydbt.h"

PlayerGameHistoryDBT::PlayerGameHistoryDBT()
{

}

PlayerGameHistoryDBT::PlayerGameHistoryDBT(DBTool*db, std::string name) :DBTable (db, name)
{
// Load SQL specific to child class.
store_template_sql();
store_create_sql();

// must build table sepparately so new
// sql can be properly registered
build_table();
}

PlayerGameHistoryDBT::~PlayerGameHistoryDBT(){

}

void PlayerGameHistoryDBT::store_template_sql(){
    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";
}

void PlayerGameHistoryDBT::store_create_sql(){
    //std::cerr << "calling store_create_sql from DBTableEx\n";

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  playerIDs TEXT,";
    sql_create += "  gameIDs TEXT, ";
    sql_create += " );";
}

void PlayerGameHistoryDBT::print_pgh(){
    for(int i = 0; i < curr_pgh.size(); i++){
        std::cout << curr_pgh[i] << " ";
    }
}

void PlayerGameHistoryDBT::set_pgh(std::vector<std::string> now_pgh){
    curr_pgh = now_pgh;
}

std::vector<std::string> PlayerGameHistoryDBT::ret_pgh(int iD){
    get_row(iD);
    return curr_pgh;
}

void PlayerGameHistoryDBT::set_num_rows(int n){
    n_rows = n;
}

int PlayerGameHistoryDBT::num_rows(){
    get_num_rows();
    return n_rows;
}

bool PlayerGameHistoryDBT::del_rows(){
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

bool PlayerGameHistoryDBT::get_num_rows(){
    int   retCode = 0;
    char *zErrMsg = 0;

    sql_get_num_rows = "SELECT count(*) FROM ";
    sql_get_num_rows += table_name;
    sql_get_num_rows += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_get_num_rows.c_str(),
                           cb_pgh_num_rows,
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

bool PlayerGameHistoryDBT::get_row(int iD)
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
                           cb_ret_pgh,
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

bool PlayerGameHistoryDBT::add_row(int id, std::string playerIDs, std::string gameIDs)
{
    int   retCode = 0;
    char *zErrMsg = 0;

    char  tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, item0, item1, item2, item3 ) ";
    sql_add_row += "VALUES (";

    sprintf (tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(playerIDs);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(gameIDs);

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

bool PlayerGameHistoryDBT::select_all()
{
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

int cb_ret_pgh (void  *data,
               int    argc,
               char **argv,
               char **azColName)
{



    std::cerr << "cb_ret_pgh being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    PlayerGameHistoryDBT *obj = (PlayerGameHistoryDBT *) data;

    std::vector<std::string> temp;

    for(i = 0; i < argc; i++)
    {
        temp.push_back(argv[i] ? argv[i] : "NULL");
    }

    obj->set_pgh(temp);

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

int cb_pgh_num_rows (void  *data,
               int    argc,
               char **argv,
               char **azColName)
{
    std::cerr << "cb_pgh_num_rows being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    PlayerGameHistoryDBT *obj = (PlayerGameHistoryDBT *) data;

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
