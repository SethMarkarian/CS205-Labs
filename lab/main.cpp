#include <iostream>
#include "log.h"
#include "configuration.h"

using namespace std;
Log err_log("shortened_words.txt");

int main()
{
    err_log.close_fh();
    err_log.open_empty();
    err_log << "mike:michael\n";
    err_log << "seth:sethchael\n";
    err_log << "bike:bichael";
    err_log.flush_fh();
    err_log.close_fh();
    Configuration config("shortened_words.txt");
    config.set("hi", "hello");
    config.set("bye", "goodbye");
    config.store_state();
    return 0;
}
