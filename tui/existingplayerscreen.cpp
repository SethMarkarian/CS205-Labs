#include "existingplayerscreen.h"

ExistingPlayerScreen::ExistingPlayerScreen()
{

}

ExistingPlayerScreen::ExistingPlayerScreen(PlayerGameHistory * pg) {
    pgh = pg;
}

void ExistingPlayerScreen::draw_screen() {
    // clear screen return cursor to (0,0)
    clear();

    for(int i = 0; i < 10; i++) {
        std::string label;
        label += i;
        label += ". ";
        if(pgh->retPlayers().size() < i) {
            label += pgh->retPlayers()[i]->getFirstName();
            label += " ";
            label += pgh->retPlayers()[i]->getLastName();
        }
        mvprintw(i, 4, label.c_str());
    }
}

void ExistingPlayerScreen::run() {
    bool continue_looping = true;
    draw_screen();
    do {

        // draw the new screen
        refresh();

        // obtain character from keyboard
        int ch = getch();
        std::string disp;

        // operate based on input character
        switch (ch) {
        case '0':
            currentPlayer = pgh->retPlayers()[0];
            break;
        case '1':
            currentPlayer = pgh->retPlayers()[1];
            break;
        case '2':
            currentPlayer = pgh->retPlayers()[2];
            break;
        case '3':
            currentPlayer = pgh->retPlayers()[3];
            break;
        case '4':
            currentPlayer = pgh->retPlayers()[4];
            break;
        case '5':
            currentPlayer = pgh->retPlayers()[5];
            break;
        case '6':
            currentPlayer = pgh->retPlayers()[6];
            break;
        case '7':
            currentPlayer = pgh->retPlayers()[7];
            break;
        case '8':
            currentPlayer = pgh->retPlayers()[8];
            break;
        case '9':
            currentPlayer = pgh->retPlayers()[9];
            break;


        }
    } while(continue_looping);

        // cleanup the window and return control to bash
        endwin();

        std::cout << "exiting run\n";
}

Player * ExistingPlayerScreen::returnCurrentPlayer() {
    return currentPlayer;
}

