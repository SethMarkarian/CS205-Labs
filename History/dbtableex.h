/*********************************************************************

Copyright (C) 2015 Jeffrey O. Pfaffmann

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*********************************************************************/

#ifndef DBTABLEEX_H
#define DBTABLEEX_H


#include <iostream>
#include <string>
#include <sqlite3.h>

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "dbtool.h"
#include "dbtable.h"

/**
 * @brief The DBTableEx class
 *
 * This is an example table class that extends the create
 * and add_row SQL definition method calls.  It also adds
 * a method for adding rows, as well as, a select method.
 * Two call backs are also provided to facilitate the new
 * method calls.
 */
class DBTableEx : public DBTable {

protected:

    std::string sql_select_all;

public:

    DBTableEx();
    DBTableEx(DBTool     *db,
              std::string name);

    ~DBTableEx();

    // An overloaded method to generate a new
    // create command for your child class.
    void store_create_sql();

    // An overloaded method to generate a new
    // insert command for your child class.
    virtual void store_template_sql();

    bool add_row(int id,
                 std::string item0, int   item1,
                 std::string item2, float item3 );

    bool select_all();
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

#endif // DBTABLEEX_H
