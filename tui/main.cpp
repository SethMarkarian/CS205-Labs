#include <iostream>
#include "screen.h"
#include "robotstui.h"
#include "wormstui.h"

int main()
{
    //RobotsTUI r;
    //r.run();
    WormsTUI w(10,20);
    w.run();
    return 0;
}
