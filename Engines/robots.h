#ifndef ROBOTS_H
#define ROBOTS_H
#define ROWS 10
#define COLS 6
#include <iostream>
#include "engine.h"

class Robots : public engine
{

public:
    /**
     * @brief array of robot positions
     */
    std::pair<int, int> robots[4];

    /**
     * @brief player with position
     */
    std::pair<int, int> player;

    /**
     * @brief Robots constructor, hard coded positions (TESTING ONLY)
     */
    Robots();

    /**
     * @brief Robots constructor, random positions
     */
    Robots(int r, int c);

    /**
      * @brief ~Robots destructor
      */
    ~Robots();

    /**
     * @brief movePlayer moves player based on input "n, s, e, w, ne, nw, se, sw, *"
     * @param movement direction
     */
    void movePlayerN();

    void movePlayerS();

    void movePlayerE();

    void movePlayerW();

    void movePlayerNE();

    void movePlayerNW();

    void movePlayerSE();

    void movePlayerSW();

    /**
     * @brief moveRobots based on where the player moved
     */
    void moveRobots();

    /**
     * @brief randomTeleport teleports player to a random position on the grid
     */
    void randomTeleport();

    /**
     * @brief isDead determines if 2 robots collided when moved
     */
    void isDead();

    /**
     * @brief win
     * @return T if win or F if no win
     */
    bool win();

    /**
     * @brief updateBoard moves pieces on the board after methods have been called
     */
    void updateBoard();


    int getRows();

    int getCols();

    bool playerDead();

    char get(int row, int col);



};

#endif // ROBOTS_H
