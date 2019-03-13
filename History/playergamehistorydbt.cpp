#include "playergamehistorydbt.h"

PlayerGameHistoryDBT::PlayerGameHistoryDBT()
{

}

PlayerGameHistoryDBT::PlayerGameHistoryDBT(DBTool*db, std::string name) :DBTable (db, name)
{
// Load SQL specific to child class.
store_add_row_sql();
store_create_sql();

// must build table sepparately so new
// sql can be properly registered
build_table();
}

void PlayerGameHistoryDBT::store_add_row_sql(){
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

