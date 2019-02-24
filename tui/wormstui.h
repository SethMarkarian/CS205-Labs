#ifndef WORMSTUI_H
#define WORMSTUI_H
#include "screen.h"
#include "../Engines/worm.h"
#include "../Engines/engine.h"

class WormsTUI : public Screen
{
    int r; // rows
    int c; // columns
    void draw_screen(); // draws the TUI display
    Worm wurm; // worm engine being played
    int key_presses; // amount of key presses user has made
public:
    /**
     * @brief WormsTUI no arguments constructor
     */
    WormsTUI();
    /**
     * @brief run runs the game
     */
    void run();
};

#endif // WORMSTUI_H
