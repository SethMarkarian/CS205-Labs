#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <curses.h>


class Screen
{
protected:
    void draw_screen();
public:
    Screen();
    void run();
};

#endif // SCREEN_H
