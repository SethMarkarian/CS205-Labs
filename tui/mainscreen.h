#ifndef MAINSCREEN_H
#define MAINSCREEN_H
#include "screen.h"
#include "../History/player.h"
#include "../History/playergamehistory.h"
#include "newplayerscreen.h"
#include "existingplayerscreen.h"
#include "topthreeplayersscreen.h"
#include "topthreegamesscreen.h"
#include "statisticsscreen.h"
#include "robotstui.h"
#include "wormstui.h"

class MainScreen:public Screen
{

protected:
    NewPlayerScreen nps;
    ExistingPlayerScreen eps;
    TopThreePlayersScreen ttps;
    TopThreeGamesScreen ttgs;
    StatisticsScreen ss;

    void draw_screen();
public:
    Player * curr_p;
    PlayerGameHistory * pgh;
    MainScreen();
    void run();
    void setPlayer(Player * pp);
};

#endif // MAINSCREEN_H
