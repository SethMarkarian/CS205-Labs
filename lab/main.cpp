// The main file.
#include "log.h"
#include <fstream>
#include <cstring>

// Object of type Log globally instantiated.
Log err_log;

int main()
{
    // Here the first err_log << string will be evaluated,
    // returning err_log, so the next err_log << can be evaluated.
    err_log.close_fh();
    err_log.open_empty();
    err_log << "test " << 25 << " " << true << " " << 2.5;

    char cline[] = "hello:darkness:my:old:friend";
    char * placeholder;
    char * key;
    char * val;
    placeholder = strtok(cline, ":");
    key = strtok(NULL, ":");
    val = strtok(NULL, ":");
    std::cout << placeholder;
    std::cout << key;
    std::cout << val;

    return 0;
}
