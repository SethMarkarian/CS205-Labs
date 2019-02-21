#ifndef WORMSTUI_H
#define WORMSTUI_H
#include "screen.h"
#include "../Engines/worm.h"
#include "../Engines/engine.h"

class WormsTUI : public Screen
{
    int r;
    int c;
    void draw_screen();
    Worm wurm; //= Worm(10, 10);
    int key_presses;
public:
    WormsTUI();
    void run();
};

#endif // WORMSTUI_H
