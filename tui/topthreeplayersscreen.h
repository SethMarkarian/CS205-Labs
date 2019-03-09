#ifndef TOPTHREEPLAYERSSCREEN_H
#define TOPTHREEPLAYERSSCREEN_H

#include <iostream>
#include <string>
#include <curses.h>

#include "../History/playergamehistory.h"

class TopThreePlayersScreen
{
protected:
    PlayerGameHistory * pgh;
    void draw_screen();
public:
    TopThreePlayersScreen();
    TopThreePlayersScreen(PlayerGameHistory * pg);
    void run();
};

#endif // TOPTHREEPLAYERSSCREEN_H
