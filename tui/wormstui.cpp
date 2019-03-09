#include "wormstui.h"

WormsTUI::WormsTUI()
{
    // initializes instance variables
    r = 20;
    c = 20;
    wurm = new Worm(r, c);
    key_presses = 0;
}

WormsTUI::WormsTUI(int ro, int co)
{
    r = ro;
    c = co;
    wurm = new Worm(r, c);
    key_presses = 0;
}

WormsTUI::~WormsTUI()
{
    delete wurm;
}

void WormsTUI::draw_screen()
{
    // temporary display string for storing the value
    // of the displayed Value object.
    std::string display;

    // clear screen return cursor to (0,0)
    clear();
    int p = 0; // this is the row to be printed on
    // instructions
    mvprintw(p++, 4, "Instructions: ");
    mvprintw(p++, 4, "Right arrow: worm goes right");
    mvprintw(p++, 4, "Left arrow: worm goes left");
    mvprintw(p++, 4, "Up arrow, worm goes up");
    mvprintw(p++, 4, "Down arrow, worm goes down");
    mvprintw(p++, 4, "q: game quits");
    mvprintw(p++, 4, "if won or lost, press q to quit or p to play again");
    // prints each row of the game board
    int i = 0;
    for(; i < r; i ++)
    {
        std::string disp;
        for(int j = 0; j < c; j++)
        {
            disp += wurm->get(i, j);
        }
        mvprintw(p++, 0, disp.c_str());
    }
    // score
    mvprintw(p++, 4, "Score:");
    std::string sc = std::to_string(wurm -> score);
    mvprintw(p++, 4, sc.c_str());
    // other information useful to user
    mvprintw(p++, 4, "Key presses!");
    std::string k_p = std::to_string(key_presses);
    mvprintw(p++, 4, k_p.c_str());
    mvprintw(p++, 4, "Have you lost/ won yet?");
    if(wurm->won_yet)
    {
        mvprintw(p++, 4, "You have won!");
    }
    else if(wurm->lost_yet)
    {
        mvprintw(p++, 4, "You have lost!");
    }
    else
    {
        mvprintw(p++, 4, "Still playing!");
    }
}

void WormsTUI::run()
{
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
            draw_screen();

            // obtain character from keyboard
            int ch = getch();
            if(!wurm->lost_yet && !wurm->won_yet) // if the user has not won or lost yet, continue playing
            {
                // operate based on input character
                switch (ch) {
                case KEY_DOWN:
                    wurm->down();
                    key_presses++;
                    break;
                case KEY_UP:
                    wurm->up();
                    key_presses++;
                    break;
                case KEY_LEFT:
                    wurm->left();
                    key_presses++;
                    break;
                case KEY_RIGHT:
                    wurm->right();
                    key_presses++;
                    break;
                case 'q':
                    continue_looping = false;
                    break;
                }
            }
            else { // if the user has won or lost, either quit or play other game
                switch(ch)
                {
                case 'q':
                    continue_looping = false;
                    break;
                case 'p':
                    wurm->place();
                    key_presses = 0;
                    break;
                }
            }
        } while(continue_looping);

            // cleanup the window and return control to bash
            endwin();

            std::cout << "exiting run\n";
}

int WormsTUI::getScore() {
    return wurm->score;
}
