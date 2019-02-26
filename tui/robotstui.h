#ifndef ROBOTSTUI_H
#define ROBOTSTUI_H

#include "screen.h"
#include "../Engines/robots.h"
#include "../Engines/engine.h"


class RobotsTUI : public Screen
{
    Robots* r;
    void draw_screen();

public:
    RobotsTUI();
    ~RobotsTUI();
    RobotsTUI(int ro, int co);
    void run();
};

#endif // ROBOTSTUI_H
