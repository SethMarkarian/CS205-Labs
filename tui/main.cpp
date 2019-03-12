
#include <iostream>
#include "screen.h"
#include "robotstui.h"
#include "wormstui.h"
#include "mainscreen.h"
#include "../History/player.h"
//#include "altscreen.h"

int main()
{
    //RobotsTUI r;
    //r.run();
    //WormsTUI w(10,20);
    //w.run();
    MainScreen ms;
    ms.run();
    //AltScreen as;
    //as.run();
    //Player *p = new Player(nullptr, "chloe", "dorward", "hewwo");
    //std::cout << p->getFirstName();
    return 0;
}
