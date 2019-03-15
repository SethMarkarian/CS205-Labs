#ifndef PLAYERGAMEHISTORYDBT_H
#define PLAYERGAMEHISTORYDBT_H

#include <iostream>
#include <string>
#include <sqlite3.h>

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "dbtool.h"
#include "dbtable.h"

#include <vector>

class PlayerGameHistoryDBT : public DBTable {

protected:

    std::string sql_select_all;
    std::string sql_get_row;
    std::string sql_get_num_rows;
    std::string sql_del_rows;
    std::vector<std::string> curr_pgh;
    int n_rows;

public:
    PlayerGameHistoryDBT();
    PlayerGameHistoryDBT(DBTool     *db,
                         std::string name);
    ~PlayerGameHistoryDBT();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_template_sql();

    bool add_row(int id, std::string playerIDs, std::string gameIDs);

    bool select_all();

    bool get_row(int iD);

    void set_pgh(std::vector<std::string> now_pgh);

    std::vector<std::string> ret_pgh(int iD);

    void print_pgh();

    int num_rows();

    bool get_num_rows();

    void set_num_rows(int n);

    bool del_rows();
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
int cb_ret_pgh(void  *data,
                  int    argc,
                  char **argv,
                  char **azColName);

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_pgh_num_rows(void  *data,
                  int    argc,
                  char **argv,
                  char **azColName);

// This is a callback function that is sent to the library and used
// to parse the sql request being sent to the database.
int cb_del_rows(void  *data,
                  int    argc,
                  char **argv,
                  char **azColName);
#endif // PLAYERGAMEHISTORYDBT_H
