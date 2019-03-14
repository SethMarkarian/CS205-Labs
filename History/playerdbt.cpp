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
