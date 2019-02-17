#ifndef ROBOTS_H
#define ROBOTS_H
#define ROWS 5
#define COLS 3
#include <iostream>

class Robots
{
public:
    /**
     * @brief gameboard
     */
    char gameboard[ROWS][COLS];

    /**
     * @brief array of robot positions
     */
    std::pair<int, int> robots[3];

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
    Robots(std::string s);

    /**
      * @brief ~Robots destructor
      */
    ~Robots();

    /**
     * @brief movePlayer moves player based on input "n, s, e, w, ne, nw, se, sw, *"
     * @param movement direction
     */
    void movePlayer(std::string movement);

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
     * @return T if 2 robots collided, F if none collided
     */
    bool isDead();

    /**
     * @brief win
     * @return T if win or F if no win
     */
    bool win();

    /**
     * @brief updateBoard moves pieces on the board after methods have been called
     */
    void updateBoard();

};

#endif // ROBOTS_H
