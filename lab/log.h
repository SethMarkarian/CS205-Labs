#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <string>
#include <iostream>

/*! The header file for the minimal Log class */
//! The log class creates, edits, and closes .txt files
class Log
{

    // File name
    std::string fn; /*! File name */

    bool state; /*! File state, true if open, false if closed */

    std::ofstream fh; /*! The file handler */



public:
    /*! default constructor */
    Log();

    /*! constructor with file name passed as a parameter */
    Log(std::string file_name);

    /*! destructor */
    ~Log();

    /*! opens file handler */
    void open_fh();

    /*! closes file handler */
    void close_fh();

    /*! flushes file handler */
    void flush_fh();

    /*! opens file handler and appends */
    void open_append();

    /*! opens an empty file handler */
    void open_empty();

    /*! returns status of the file, true if open, false if closed */
    bool det_state();

    /*! overrides the "<<" operator for strings */
    Log& operator<<(const std::string& str);

    /*! overrides the "<<" operator for char */
    Log& operator<<(const char* c);

    /*! overrides the "<<" operator for int */
    Log& operator<<(int n);

    /*! overrides the "<<" operator for bool */
    Log& operator<<(bool b);

    /*! overrides the "<<" operator for double */
    Log& operator<<(double d);
};

#endif // LOG_H
