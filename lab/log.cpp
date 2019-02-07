// The source file for the minimal Log class
#include "log.h"

// In the default constructor the file handler is opened.
Log::Log()
{
    Log("./exampleLogFile.txt");
}

Log::Log(std::string file_name)
{
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

void Log::open_fh()
{
    fh.open(fn, std::ofstream::out | std::ofstream::app); //over write, change app to trunc
    if(!fh)
    {
        std::cerr << "Unable to open file " << fn;
        exit(1); // call system to stop
    }
}

void Log::close_fh()
{
    fh.close();
}

void Log::flush_fh()
{
    fh.flush();
}

void Log::open_empty()
{
    fh.open(fn, ios::noreplace);
    /*fh.open(fn, std::ofstream::out | std::ofstream::app);
    if(!fh)
    {

    }*/
}
