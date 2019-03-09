#include "topthreeplayersscreen.h"

TopThreePlayersScreen::TopThreePlayersScreen()
{

}

TopThreePlayersScreen::TopThreePlayersScreen(PlayerGameHistory * pg) {
    pgh = pg;
}

void TopThreePlayersScreen::draw_screen() {
    clear();

    for(int i = 0; i < 3; i++) {
        std::string label;
        label += i;
        label += ". ";
        if(pgh->top_3().size() < i) {
            label += pgh->top_3()[i]->getFirstName();
            label += " ";
            label += pgh->top_3()[i]->getLastName();
        }
        mvprintw(i, 4, label.c_str());
    }
}

void TopThreePlayersScreen::run() {
    draw_screen();

    endwin();

    std::cout << "exiting run\n";
}
