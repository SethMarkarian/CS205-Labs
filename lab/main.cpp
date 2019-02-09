// The main file.
#include "log.h"
#include <fstream>

// Object of type Log globally instantiated.
//Log err_log;

int main()
{
    Log err_log;
    //err_log.open_empty();
    // Here the first err_log << string will be evaluated,
    // returning err_log, so the next err_log << can be evaluated.
    err_log.open_append();
    std::cout << err_log.fh.is_open();
    err_log.fh << 2;
    std::cout << err_log.fh.is_open();
    err_log << 12;
    std::cout << err_log.fh.is_open();
    err_log.fh << 1;
    std::cout << err_log.fh.is_open();
    //err_log.flush_fh();
    //err_log.close_fh();

    std::ofstream of;
    of.open("hello.txt", std::ofstream::out | std::ofstream::trunc);
    of << "hello";
    of.close();

    return 0;
}
