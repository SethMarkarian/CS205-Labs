#ifndef EXISTINGPLAYERSCREEN_H
#define EXISTINGPLAYERSCREEN_H
#include <iostream>
#include <string>
#include <curses.h>

#include "../History/playergamehistory.h"

class ExistingPlayerScreen
{
protected:
    PlayerGameHistory * pgh;
    Player * currentPlayer;
    void draw_screen();
public:
    ExistingPlayerScreen();
    ExistingPlayerScreen(PlayerGameHistory * pg);
    void run();
    Player * returnCurrentPlayer();
};

#endif // EXISTINGPLAYERSCREEN_H
