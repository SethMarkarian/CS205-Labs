#include "playerdbt.h"

PlayerDBT::PlayerDBT()
{

}

PlayerDBT::PlayerDBT(DBTool* db, std::string name) : DBTable (db, name)
{
    // Load SQL specific to child class.
    store_template_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
}

PlayerDBT::~PlayerDBT(){

}

void PlayerDBT::store_template_sql(){
    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";
}

void PlayerDBT::store_create_sql(){
    //std::cerr << "calling store_create_sql from DBTableEx\n";

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += "  id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  fn TEXT NOT NULL,";
    sql_create += "  ln TEXT NOT NULL, ";
    sql_create += "  ad TEXT NOT NULL, ";
    sql_create += "  gameID INT  NOT NULL,";
    sql_create += "  gameHistoryID INT  NOT NULL,";
    sql_create += " );";
}

void PlayerDBT::set_num_rows(int n){
    n_rows = n;
}

int PlayerDBT::num_rows(){
    get_num_rows();
    return n_rows;
}

bool PlayerDBT::get_num_rows(){

    int   retCode = 0;
    char *zErrMsg = 0;

    sql_get_num_rows = "SELECT count(*) FROM ";
    sql_get_num_rows += table_name;
    sql_get_num_rows += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_get_num_rows.c_str(),
                           cb_p_num_rows,
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

void PlayerDBT::print_p(){
    for(int i = 0; i < curr_p.size(); i++)
    {
        std::cout << curr_p[i] << " ";
    }
}

void PlayerDBT::set_p(std::vector<std::string> now_p){
    curr_p = now_p;
}

bool PlayerDBT::del_rows(){
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

bool PlayerDBT::get_row(int iD)
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
                           cb_ret_p,
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

std::vector<std::string> PlayerDBT::ret_p(int iD){
    get_row(iD);
    return curr_p;
}

bool PlayerDBT::add_row(int id, std::string fn, std::string ln, std::string ad, int gameID, int gameHistoryID)
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
    sql_add_row += std::string(fn);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(ln);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(ad);
    sql_add_row += "\", ";

    sprintf (tempval, "%d", gameID);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sprintf (tempval, "%d", gameHistoryID);
    sql_add_row += tempval;

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

bool PlayerDBT::select_all()
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

int cb_ret_p (void  *data,
               int    argc,
               char **argv,
               char **azColName)
{



    std::cerr << "cb_ret_p being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    PlayerDBT *obj = (PlayerDBT *) data;

    std::vector<std::string> temp;

    for(i = 0; i < argc; i++)
    {
        temp.push_back(argv[i] ? argv[i] : "NULL");
    }

    obj->set_p(temp);

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

int cb_p_num_rows (void  *data,
               int    argc,
               char **argv,
               char **azColName)
{
    std::cerr << "cb_p_num_rows being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    PlayerDBT *obj = (PlayerDBT *) data;

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
