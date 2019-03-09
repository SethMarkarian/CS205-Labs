#ifndef STATISTICSSCREEN_H
#define STATISTICSSCREEN_H

#include <iostream>
#include <string>
#include <curses.h>

#include "../History/playergamehistory.h"

class StatisticsScreen
{
protected:
    PlayerGameHistory * pgh;
    void draw_screen();
public:
    StatisticsScreen();
    StatisticsScreen(PlayerGameHistory * pg);
    void run();
};

#endif // STATISTICSSCREEN_H
