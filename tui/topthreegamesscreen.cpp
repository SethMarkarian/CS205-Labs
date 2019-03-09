#include "topthreegamesscreen.h"

TopThreeGamesScreen::TopThreeGamesScreen()
{

}

TopThreeGamesScreen::TopThreeGamesScreen(PlayerGameHistory * pg) {
    pgh = pg;
}

void TopThreeGamesScreen::draw_screen() {
    clear();

    for(int i = 0; i < 3; i++) {
        std::string label;
        label += i;
        label += ". ";
        if(pgh->top_3_games().size() < i) {
            label += pgh->top_3_games()[i]->getPlayer().getFirstName();
            label += " ";
            label += pgh->top_3_games()[i]->getFinalScore();
        }
        mvprintw(i, 4, label.c_str());
    }
}

void TopThreeGamesScreen::run() {
    draw_screen();

    endwin();

    std::cout << "exiting run\n";
}
