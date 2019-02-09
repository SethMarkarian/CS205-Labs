#ifndef LOG_H
#define LOG_H

// The header file for the minimal Log class
#include <fstream>
#include <string>
#include <iostream>

class Log
{

    // File name
    std::string fn;
    // File state, true if open, false if closed
    bool state;



public:
    Log(); // default constructor
    Log(std::string file_name); // constructor with file name passed as a parameter
    ~Log(); // destructor

    // The file handler
    std::ofstream fh;

    void open_fh();
    void close_fh();
    void flush_fh();
    void open_append();
    void open_empty();
    bool det_state(); // Returns true if open, false if closed

    // overloaded handler operator
    //Log& operator<<(const std::string& str);
    //Log& operator<<(const char* c);
    Log& operator<<(int n);
    Log& operator<<(bool b);
    Log& operator<<(double d);
    // other datatypes to overload: int, long, short, this doesn't seem feasible
    // can we pass in an auto in a parameter
    // pick a few

};

#endif // LOG_H
