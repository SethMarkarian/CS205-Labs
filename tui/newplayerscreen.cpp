#include "newplayerscreen.h"

void NewPlayerScreen::fields_fill()
{
    field[0] = new_field(1, 10, 1, 18, 0, 0);
    field[1] = new_field(1, 10, 2, 18, 0, 0);
    field[2] = new_field(1, 10, 3, 18, 0, 0);
    field[3] = NULL;
}

void NewPlayerScreen::disp_labels()
{
    mvprintw(1, 4, "First name: ");
    mvprintw(2, 4, "Last name: ");
    mvprintw(3, 4, "Address: ");
}
