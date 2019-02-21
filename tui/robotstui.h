#ifndef ROBOTSTUI_H
#define ROBOTSTUI_H

#include "screen.h"
#include "../Engines/robots.h"
#include "../Engines/engine.h"


class RobotsTUI : public Screen
{
    Robots r;

protected:
    void draw_screen();
public:
    RobotsTUI();
    void run();
};

#endif // ROBOTSTUI_H
