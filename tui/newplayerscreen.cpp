#include "newplayerscreen.h"

NewPlayerScreen::NewPlayerScreen() {

}

void NewPlayerScreen::startup() {
    // Initialize the interaction loop to run.
    continue_looping = true;
    // initialize displayed fields
    this->fields_fill();
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
    this->disp_labels();

    // perform last refresh
    refresh();
}

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

void NewPlayerScreen::run()
{
    startup();
    receiving();
    closing();
}

void NewPlayerScreen::receiving() {
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

void NewPlayerScreen::closing() {
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

std::vector<char *> NewPlayerScreen::get_f_vals()
{
    return f_vals;
}
