#ifndef MAINSCREEN_H
#define MAINSCREEN_H
#include "screen.h"
#include "../History/player.h"
#include "../History/playergamehistory.h"

class MainScreen:public Screen
{
    Player * p;
    PlayerGameHistory * pgh;
protected:
    void draw_screen();
public:
    MainScreen();
    void run();
};

#endif // MAINSCREEN_H
