#include "mainscreen.h"

MainScreen::MainScreen()
{
    p = new Player(nullptr, nullptr, nullptr, nullptr);
    nps = NewPlayerScreen();
    eps = ExistingPlayerScreen(pgh);
    ttps = TopThreePlayersScreen(pgh);
    ttgs = TopThreeGamesScreen(pgh);
    ss = StatisticsScreen(pgh);
}

void MainScreen::draw_screen()
{
    // clear screen return cursor to (0,0)
    clear();
    std::string first_line;
    first_line = "Current Player: ";
    (p -> getFirstName() == nullptr) ? first_line += "No Player Selected" : first_line += p -> getFirstName();
    first_line += ' ';
    (p -> getLastName() == nullptr) ? first_line += "" : first_line += p -> getLastName();
    // first_line += p -> getLastName();
    // print the state of the value object
    mvprintw(1, 4, first_line.c_str());
    mvprintw(3, 4, "a. Create a New Player");
    mvprintw(4, 4, "b. Select an Existing Player");
    mvprintw(6, 4, "c. Display Top Three Players");
    mvprintw(7, 4, "d. Display Top Three Games Played");
    mvprintw(8, 4, "e. Display Calculated Statistics");
    mvprintw(10, 4, "f. Play Robots");
    mvprintw(11, 4, "g. Play Worm");
    mvprintw(13, 4, "q. Exit Program");
}

void MainScreen::run()
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
    char * name = (char * )'w';
    Game g = Game(p, name, 0);
    WormsTUI w;
    w.run();
    g.setFinalScore(w.getScore());
    p->addGame(&g);
    std::string fn;
    std::string ln;
    std::string ad;
    std::string len;
    // draw the current screen
    draw_screen();
    //AltScreen as;
    //NewPlayerScreen nps;
    //ExistingPlayerScreen eps(pgh);

    do {
        draw_screen();
        // draw the new screen
        refresh();

        // obtain character from keyboard
        int ch = getch();
        std::string disp;

        // operate based on input character
        switch (ch) {
        case 'a':
            // Create a New Player
            // Need Player FN, LN, Address
            // Create a New Player, add to PlayerGameHistory
            // as.run();
            nps.run();
            //fn = nps.get_f_vals()[0];
            //ln = nps.get_f_vals()[1];
            //ad = nps.get_f_vals()[2];
            //len = "";
            //len += nps.get_f_vals().size();
            //p = new Player(nullptr, (char*)fn.c_str(), (char*)fn.c_str(), (char*)fn.c_str());
            draw_screen();
            mvprintw(14, 4, "test");
            break;
        case 'b':
            eps.run();
            p = eps.returnCurrentPlayer();
            draw_screen();
            break;
        case 'c':
            ttps.run();
            draw_screen();
            break;
        case 'd':
            ttgs.run();
            draw_screen();
            break;
        case 'e':
            ss.run();
            draw_screen();
            break;
        case 'f':{
            if(p->getFirstName() != nullptr) {
                char * name = (char * )'r';
                Game g = Game(p, name, 0);
                RobotsTUI r;
                r.run();
                g.setFinalScore(r.getScore());
                p->addGame(&g);
            }char * name = (char * )'w';
            Game g = Game(p, name, 0);
            WormsTUI w;
            w.run();
            g.setFinalScore(w.getScore());
            p->addGame(&g);
            draw_screen();
            break;
        }
        case 'g': {
            if(p->getFirstName() != nullptr) {
                char * name = (char * )'w';
                Game g = Game(p, name, 0);
                WormsTUI w;
                w.run();
                g.setFinalScore(w.getScore());
                p->addGame(&g);
            }
            draw_screen();
            break;
        }
        case 'q':
            // Exit program
            continue_looping = false;
            break;

        }
    } while(continue_looping);

        // cleanup the window and return control to bash
        endwin();

        std::cout << "exiting run\n";
}

void MainScreen::setPlayer(Player * pp) {
    p = pp;
}
