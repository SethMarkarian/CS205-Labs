#include "robotstui.h"

RobotsTUI::RobotsTUI()
{
    //r = Robots(10,6);
}

void RobotsTUI::draw_screen() {
    // temporary display string for storing the value
    // of the displayed Value object.


    // clear screen return cursor to (0,0)
    clear();
    r.isDead();
    r.moveRobots();
    r.updateBoard();

    for(int i = 0; i < r.getRows(); i++ ) {
        std::string display;
        for(int j = 0; j < r.getCols(); j++) {
            display += r.get(i, j);
        }
        //mvprintw(i, 0, display.c_str());
        printw(display.c_str());
        move(i, 0);
    }
}

void RobotsTUI::run() {
    // initialize the screen
    initscr();

    // hide the cursor from view (comment this line out for debugging)
    curs_set(0);

    // disables line buffering and erase/kill character-processing
    // (interrupt and flow control characters are unaffected),
    // making characters typed by the  user  immediately
    // available to the program
    cbreak();

    // control whether characters  typed  by  the user  are echoed
    // by getch as they are typed
    noecho();

    // the user can press a function key (such as an arrow key) and
    // getch returns a single value representing the  function  key,
    // as in KEY_LEFT
    keypad(stdscr, TRUE);

    // initialize the interaction loop to run
    bool continue_looping = true;

    // draw the current screen
    refresh();
    draw_screen();

    do {

        // draw the new screen
        refresh();
        draw_screen();

        // obtain character from keyboard
        int ch = getch();

        if(r.win()) {
            continue_looping = false;
        }
        if(r.playerDead()) {
            continue_looping = false;
        }
        // operate based on input character
        switch (ch) {
        case KEY_DOWN:
            r.movePlayerS();
            break;
        case KEY_UP:
            r.movePlayerN();
            break;
        case KEY_LEFT:
            r.movePlayerW();
            break;
        case KEY_RIGHT:
            r.movePlayerE();
            break;
        case '*':
            r.randomTeleport();
            break;
        case 'q':
            continue_looping = false;
            break;
        }
    } while(continue_looping);

        // cleanup the window and return control to bash
        endwin();

        std::cout << "exiting run\n";

}
