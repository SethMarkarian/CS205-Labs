// The main file.
#include "log.h"

// Object of type Log globally instantiated.
Log err_log;

int main(int argc, char *argv[])
{
    // Here the first err_log << string will be evaluated.
    err_log << "test" << "test" << "test" << "test";

    return 0;
}
