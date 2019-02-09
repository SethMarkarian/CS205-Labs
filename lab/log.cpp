// The source file for the minimal Log class
#include "log.h"

// In the default constructor the file handler is opened.
Log::Log()
{
    Log("./exampleLogFile.txt");
}

Log::Log(std::string file_name)
{
    state = true;
    fn = file_name;
    fh.open(fn, std::ofstream::out | std::ofstream::app);
}

// In the destructor the file handler is closed.
Log::~Log()
{
    fh.close();
}

// The overloaded operator will process the incoming string, then return
// itself as a reference. This allows chaining of multiple filehandle
// operations.
Log& Log::operator<<(std::string str)
{
    fh << str;
    return *this;
}

Log& Log::operator<<(int n)
{
    fh << n;
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
    fh.open(fn, std::ios::app | std::ios::trunc);
}
void Log::open_append(std::string s)
{
    fh.open(fn, std::ios::app);
    fh << s;
}

bool Log::det_state() {
    return state;
}

