// The source file for the minimal Log class
#include "log.h"

// In the default constructor the file handler is opened.
Log::Log()
{
    Log("./exampleLogFile1.txt");
}

Log::Log(std::string file_name)
{
    state = true;
    fn = file_name;
    fh.open(fn, std::ofstream::out | std::ofstream::app);
    fh << "hello";
    *this << 10;
}

// In the destructor the file handler is closed.
Log::~Log()
{
    fh.close();
}

// The overloaded operator will process the incoming string, then return
// itself as a reference. This allows chaining of multiple filehandle
// operations.
/*
Log& Log::operator<<(const std::string& str)
{
    fh << str;
    return *this;
}

Log& Log::operator<<(const char* c)
{
    fh << c;
    return *this;
}
*/

Log& Log::operator<<(int n)
{
    fh << n;
    std::cout << fh.is_open();
    return *this;
}


Log& Log::operator<<(bool b)
{
    fh << b;
    return *this;
}

Log& Log::operator<<(double d)
{
    fh << d;
    return *this;
}

void Log::open_fh()
{
    state = true;
    fh.open(fn, std::ofstream::out | std::ofstream::app); //over write, change app to trunc
    if(!fh)
    {
        std::cerr << "Unable to open file " << fn;
        exit(1); // call system to stop
    }
}

void Log::close_fh()
{
    state = false;
    fh.close();
}

void Log::flush_fh()
{
    fh.flush();
}

void Log::open_empty()
{
    state = true;
    fh.open(fn, std::ios::out | std::ios::trunc);
}

void Log::open_append()
{
    fh.open(fn, std::ios::out | std::ios::app);
}

bool Log::det_state() {
    return state;
}

