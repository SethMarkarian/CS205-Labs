#ifndef TOPTHREEGAMESSCREEN_H
#define TOPTHREEGAMESSCREEN_H

#include <iostream>
#include <string>
#include <curses.h>

#include "../History/playergamehistory.h"

class TopThreeGamesScreen
{
protected:
    PlayerGameHistory * pgh;
    void draw_screen();
public:
    TopThreeGamesScreen();
    TopThreeGamesScreen(PlayerGameHistory * pg);
    void run();
};

#endif // TOPTHREEGAMESSCREEN_H
