#ifndef WORMSTUI_H
#define WORMSTUI_H
#include "screen.h"
#include "../Engines/worm.h"

class WormsTUI : public Screen
{
    void draw_screen();
public:
    WormsTUI();
    void run();
};

#endif // WORMSTUI_H
