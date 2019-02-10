// The source file for the minimal Log class
#include "log.h"

// In the default constructor the file handler is opened.
Log::Log()
{
    state = true;
    fn = "./exampleLogFile.txt";
    fh.open(fn, std::ofstream::out | std::ofstream::app);
}

Log::Log(std::string file_name)
{
    state = true;
    fn = file_name;
    try {
        fh.open(fn, std::ofstream::out | std::ofstream::app);
    }
    catch (int e) {
        std::cout << "Exception: " << e;
    }

}

// In the destructor the file handler is closed.
Log::~Log()
{
    fh.close();
}

// The overloaded operator will process the incoming string, then return
// itself as a reference. This allows chaining of multiple filehandle
// operations.

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
    try {
        state = true;
        fh.open(fn, std::ofstream::out | std::ofstream::app); //over write, change app to trunc
        if(!fh)
        {
            std::cerr << "Unable to open file " << fn;
            exit(1); // call system to stop
        }
    }
    catch (int e) {
        std::cout << "Exception: " << e;
    }

}

void Log::close_fh()
{
    try {
        state = false;
        fh.close();
    }
    catch (int e) {
        std::cout << "Exception: " << e;
    }

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
