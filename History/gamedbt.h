#ifndef GAMEDBT_H
#define GAMEDBT_H

#include <iostream>
#include <string>
#include <sqlite3.h>

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "dbtool.h"
#include "dbtable.h"

#include <vector>

class GameDBT : public DBTable {

protected:

    std::string sql_select_all;
    std::string sql_get_row;
    std::vector<std::string> curr_game;

public:
    GameDBT();
    GameDBT(DBTool     *db,
            std::string name);
    ~GameDBT();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    bool add_row(int id, std::string gameName, int finalScore, int playerID);

    bool select_all();

    bool get_row(int iD);

    void set_game(std::vector<std::string> now_game);

    std::vector<std::string> ret_game(int iD);

    void print_game();
};


// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_add_row(void  *data,
               int    argc,
               char **argv,
               char **azColName);


// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_select_all(void  *data,
                  int    argc,
                  char **argv,
                  char **azColName);

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_ret_game(void  *data,
                  int    argc,
                  char **argv,
                  char **azColName);
#endif // GAMEDBT_H
