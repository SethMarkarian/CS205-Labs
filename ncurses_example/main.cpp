#include <iostream>
#include <string>
#include <curses.h>
#include "value.h"

// forward reference of function with a passed reference
// to an object
void draw_screen(Value &v);

int main()
{
    Value v;

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
    draw_screen(v);

    do {

        // draw the new screen
        refresh();

        // obtain character from keyboard
        int ch = getch();

        // operate based on input character
        switch (ch) {
        case KEY_DOWN:
            v--;
            break;
        case KEY_UP:
            v++;
            break;
        case KEY_LEFT:
            v = 0;
            break;
        case KEY_RIGHT:
            continue_looping = false;
            break;
        }

        draw_screen(v);

    } while(continue_looping);

    // cleanup the window and return control to bash
    endwin();

    std::cout << "exiting main\n";
    return 0;
}

// a function for drawing the current screen
void draw_screen(Value &v) {

    // temporary display string for storing the value
    // of the displayed Value object.
    std::string display;

    // clear screen return cursor to (0,0)
    clear();

    // print the state of the value object
    mvprintw(2, 4, "Current Value : ");
    display = std::to_string(v.get());
    mvprintw(2, 21, display.c_str());

    // print the instructions for manipulating the Value object
    mvprintw(5, 4, "Up Arrow    : increments value");
    mvprintw(6, 4, "Down Arrow  : decrements value");
    mvprintw(7, 4, "Left Arrow  : resets value to zero");
    mvprintw(8, 4, "Right Arrow : exits program");


}
