#include "statisticsscreen.h"

StatisticsScreen::StatisticsScreen()
{

}

StatisticsScreen::StatisticsScreen(PlayerGameHistory * pg) {
    pgh = pg;
}

void StatisticsScreen::draw_screen() {
    clear();

    std::string avgScoreString;
    avgScoreString += "Average Score: ";
    avgScoreString += pgh->avgScore();
    mvprintw(1, 4, avgScoreString.c_str());

    std::string topScoreString;
    avgScoreString += "Top Score: ";
    avgScoreString += pgh->topScore();
    mvprintw(2, 4, topScoreString.c_str());

    std::string numPlayersString;
    avgScoreString += "Number of Players: ";
    avgScoreString += pgh->numPlayers();
    mvprintw(3, 4, numPlayersString.c_str());

    std::string numGamesString;
    avgScoreString += "Number of Games: ";
    avgScoreString += pgh->numGamesPlayed();
    mvprintw(4, 4, numGamesString.c_str());

    std::string avgGamePerPlayerString;
    avgScoreString += "Average Games Per Player: ";
    avgScoreString += pgh->avgGamesPerPlayer();
    mvprintw(5, 4, avgGamePerPlayerString.c_str());
}

void StatisticsScreen::run() {
    draw_screen();

    endwin();

    std::cout << "exiting run /n";
}
