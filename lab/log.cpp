#include "log.h"

/*! In the default constructor the file handler is opened. */
Log::Log()
{
    state = true;
    fn = "./exampleLogFile.txt";
    fh.open(fn, std::ofstream::out | std::ofstream::app);
}
/*! constructor for a string file name
 * \param file_name file name
*/
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

/*! In the destructor the file handler is closed. */
Log::~Log()
{
    fh.close();
}

// The overloaded operator will process the incoming string, then return
// itself as a reference. This allows chaining of multiple filehandle
// operations.

/*! overrides the "<<" operator for strings
    \param str string to be sent
    \return Log reference*/
Log& Log::operator<<(const std::string& str)
{
    fh << str;
    return *this;
}
/*! overrides the "<<" operator for char
    \param c char to be sent
    \return Log reference*/
Log& Log::operator<<(const char* c)
{
    fh << c;
    return *this;
}
/*! overrides the "<<" operator for int
    \param n int to be sent
    \return Log reference*/
Log& Log::operator<<(int n)
{
    fh << n;
    return *this;
}
/*! overrides the "<<" operator for boolean
    \param b boolean to be sent
    \return Log reference*/
Log& Log::operator<<(bool b)
{
    fh << b;
    return *this;
}
/*! overrides the "<<" operator for double
    \param d string to be sent
    \return Log reference*/
Log& Log::operator<<(double d)
{
    fh << d;
    return *this;
}

/*! opens file hander */
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

/*! closes file handler */
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

/*! flushes file handler */
void Log::flush_fh()
{
    fh.flush();
}

/*! opens an empty file handler */
void Log::open_empty()
{
    state = true;
    fh.open(fn, std::ios::out | std::ios::trunc);
}

/*! opens file handler and appends */
void Log::open_append()
{
    fh.open(fn, std::ios::out | std::ios::app);
}

/*! returns status of the file, true if open, false if closed
    \return status, true -> open, false -> closed*/
bool Log::det_state() {
    return state;
}
