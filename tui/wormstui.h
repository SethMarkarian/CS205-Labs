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
    Worm * wurm; // worm engine being played
    int key_presses; // amount of key presses user has made
public:
    /**
     * @brief WormsTUI no arguments constructor
     */
    WormsTUI();
    /**
     * @brief WormsTUI constructor with rows and columns input
     * @param r rows
     * @param c columns
     */
    WormsTUI(int ro, int co);
    ~WormsTUI();
    /**
     * @brief run runs the game
     */
    void run();
    int getScore();
};

#endif // WORMSTUI_H
