// The main file.
#include "log.h"

// Object of type Log globally instantiated.
Log static err_log;

int main()
{
    // Here the first err_log << string will be evaluated,
    // returning err_log, so the next err_log << can be evaluated.
    err_log << "test" << "test" << "test" << "test";

    return 0;
}
