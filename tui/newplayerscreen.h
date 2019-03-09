#ifndef NEWPLAYERSCREEN_H
#define NEWPLAYERSCREEN_H
#include "altscreen.h"
#include <string>
#include <iostream>
#include <form.h>
#include <vector>

class NewPlayerScreen
{
protected:
    FORM *my_form;
    int ch;
    bool continue_looping;
    std::vector<char *> f_vals; // stands for field values
    void receiving();
    void closing();
    void startup();

    FIELD *field[4];
    void fields_fill(); // last field must be null!
    void disp_labels();
public:
    NewPlayerScreen();
    void run();
    std::vector<char *> get_f_vals();
};

#endif // NEWPLAYERSCREEN_H
