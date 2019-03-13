#include "playerdbt.h"

PlayerDBT::PlayerDBT()
{

}

PlayerDBT::PlayerDBT(DBTool* db, std::string name) : DBTable (db, name)
{
    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
}

void PlayerDBT::store_add_row_sql(){
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
