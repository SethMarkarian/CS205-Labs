#include "screen.h"


Screen::Screen()
{

}

void Screen::run() {
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
    draw_screen();

    do {

        // draw the new screen
        refresh();

        // obtain character from keyboard
        int ch = getch();

        // operate based on input character
        switch (ch) {
        case KEY_DOWN:
            break;
        case KEY_UP:
            break;
        case KEY_LEFT:
            break;
        case KEY_RIGHT:
            continue_looping = false;
            break;

        }
    } while(continue_looping);

        // cleanup the window and return control to bash
        endwin();

        std::cout << "exiting run\n";

}

void Screen::draw_screen() {
    // temporary display string for storing the value
    // of the displayed Value object.
    std::string display;

    // clear screen return cursor to (0,0)
    clear();

    // print the state of the value object
    mvprintw(2, 4, "This is a generic Screen: ");
    display = "Hello World!";
    mvprintw(3, 21, display.c_str());

    // print the instructions for manipulating the Value object
    mvprintw(5, 4, "Instructions should go here!");
    mvprintw(6, 4, "This is at 6, 4");
    mvprintw(7, 8, "Click right arrow to quit");


}
