#ifndef ALTSCREEN_H
#define ALTSCREEN_H
#include <string>
#include <iostream>
#include <form.h>
#include <vector>

class AltScreen
{
protected:
    FORM *my_form;
    int ch;
    bool continue_looping;
    std::vector<std::string> f_vals; // stands for field values
    void receiving();
    void closing();
    void startup();

    // theoretically, this is all a child alt screen should need to edit
    FIELD *field[4];
    void fields_fill(); // last field must be null!
    void disp_labels();
public:
    AltScreen();
    void run();
    std::vector<std::string> get_f_vals();
};
#endif // ALTSCREEN_H
