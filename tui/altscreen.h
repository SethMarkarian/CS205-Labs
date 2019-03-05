#ifndef ALTSCREEN_H
#define ALTSCREEN_H
#include <string>
#include <iostream>
#include <form.h>
#include <vector>

class AltScreen
{
    FIELD *field[4];
    FORM *my_form;
    int ch;
    bool continue_looping;
    std::vector<std::string> f_vals; // stands for field values
public:
    AltScreen();
    void run();
    void receiving();
    void closing();
};

#endif // ALTSCREEN_H
