#include "altscreen.h"

AltScreen::AltScreen()
{
    initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);

}

AltScreen::~AltScreen()
{
    // how to delete a form??? and field???????
}

void AltScreen::startup()
{
    // Initialize the interaction loop to run.
    continue_looping = true;
    // initialize displayed fields
    fields_fill();
    for(int i = 0; field[i] != NULL;  i++)
    {
        // Print a line for the option.
        set_field_back(field[i], A_UNDERLINE);
        //  Don't go to next field when this field is filled up.
        field_opts_off(field[i], O_AUTOSKIP);
    }
/******** Create form. ********/
    // Create the form and post it.
    my_form = new_form(field);
    post_form(my_form);

    // build the form
    refresh();

    // display labels
    disp_labels();

    // perform last refresh
    refresh();
}

void AltScreen::fields_fill()
{
    // The parameters below are as follows:
    //  1. int height    -- The number of rows in the field.
    //  2. int width     -- The row width of the field.
    //  3. int toprow    -- The screen row where the field top is placed.
    //  4. int leftcol   -- The screen col where the field left-side is placed.
    //  5. int offscreen -- Zero shows entire field.
    //  6. int nbuffers  -- Number of additional buffers, use zero.

    field[0] = new_field(1, 10, 4, 18, 0, 0);
    field[1] = new_field(1, 10, 6, 18, 0, 0);

    // Tag end of array so ncurses knows when there are no
    // more fields.
    field[2] = NULL;
}

void AltScreen::disp_labels()
{
    // display labels
    mvprintw(4, 10, "Value 1:");
    mvprintw(6, 10, "Value 2:");
}

void AltScreen::run()
{
    startup();
    receiving();
    closing();
}

void AltScreen::receiving()
{
    // back space doesn't work. didn't work in the example either.
    /******* Loop through to get user requests *******/

    do {
        // obtain character from keyboard
        int ch = getch();

        switch(ch) {
        case KEY_DOWN:

            // go to next field
            form_driver(my_form, REQ_NEXT_FIELD);

            // Go to the end of the present buffer
            // and leave nicely at the last character
            form_driver(my_form, REQ_END_LINE);

            break;

        case KEY_UP:

            // go to previous field
            form_driver(my_form, REQ_PREV_FIELD);

            // Go to the end of the present buffer
            // and leave nicely at the last character
            form_driver(my_form, REQ_END_LINE);

            break;

        case KEY_LEFT:

            // exit from loop
            continue_looping = false;

            // stores the buffer on the field it is located
            form_driver(my_form, REQ_END_LINE);
            break;

        default:
            // If this is a normal character, print it.
            form_driver(my_form, ch);
            break;
        }

    } while (continue_looping);
}

void AltScreen::closing()
{
    // Un post form and free the memory
    unpost_form(my_form);
    free_form(my_form);
    // store contents of fields before they are freed
    for(int i = 0; field[i] != NULL;  i++) // last box of field is null
    {
        f_vals.push_back(field_buffer(field[i], 0));
        // free the field
        free_field(field[i]); // unknown if needs to be done after reading data from all fields
    }
    // exit ncurses environment
    endwin();
}

std::vector<std::string> AltScreen::get_f_vals()
{
    return f_vals;
}
