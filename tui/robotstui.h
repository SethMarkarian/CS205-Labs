#ifndef ROBOTSTUI_H
#define ROBOTSTUI_H

#include "screen.h"
#include "../Engines/robots.h"


class RobotsTUI : public Screen
{
protected:
    void draw_screen();
public:
    RobotsTUI();
    void run();
};

#endif // ROBOTSTUI_H
