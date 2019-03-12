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

    /*for(int i = 0; i < 10; i++) {
        std::string label;
        label += i;
        label += ". ";
        if(pgh->retPlayers().size() < i) {
            label += pgh->retPlayers()[i]->getFirstName();
            label += " ";
            label += pgh->retPlayers()[i]->getLastName();
        }
        mvprintw(i, 4, label.c_str());
    }*/
    std::string disp = pgh->retPlayers()[0]->getFirstName();
    for(int i = 0; i < 10 && i < pgh->retPlayers().size(); i++){
        std::string out = "";
        out += std::to_string(i);
        out += " ";
        out += pgh->retPlayers()[i]->getFirstName();
        out += " ";
        out += pgh->retPlayers()[i]->getLastName();
        out += " ";
        out += pgh->retPlayers()[i]->getAddress();
        mvprintw(i+1, 4, out.c_str());
    }
    mvprintw(0, 4, "we out here");
}

void ExistingPlayerScreen::run() {
    bool continue_looping = true;
    draw_screen();
    do {

        // draw the new screen
        refresh();

        // obtain character from keyboard
        int ch = getch();

        // operate based on input character
        switch (ch) {
        case '0':
            currentPlayer = pgh->retPlayers()[0];
            continue_looping = false;
            break;
        case '1':
            currentPlayer = pgh->retPlayers()[1];
            continue_looping = false;
            break;
        case '2':
            currentPlayer = pgh->retPlayers()[2];
            continue_looping = false;
            break;
        case '3':
            currentPlayer = pgh->retPlayers()[3];
            continue_looping = false;
            break;
        case '4':
            currentPlayer = pgh->retPlayers()[4];
            continue_looping = false;
            break;
        case '5':
            currentPlayer = pgh->retPlayers()[5];
            continue_looping = false;
            break;
        case '6':
            currentPlayer = pgh->retPlayers()[6];
            continue_looping = false;
            break;
        case '7':
            currentPlayer = pgh->retPlayers()[7];
            continue_looping = false;
            break;
        case '8':
            currentPlayer = pgh->retPlayers()[8];
            continue_looping = false;
            break;
        case '9':
            currentPlayer = pgh->retPlayers()[9];
            continue_looping = false;
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

