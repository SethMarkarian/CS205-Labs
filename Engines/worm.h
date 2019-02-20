#ifndef WORM_H
#define WORM_H
//! necessary include statements
#include <iostream>
#include <vector>
#define ROWS 5
#define COLS 5
#include <stdlib.h>
#include <map>
#include <functional>
#include <thread>
#include "engine.h"
//! The header file for the worm class
//! The worm class manages operations for a worm game
//! This is not an actual game
/*!
  \class Worm
 * \brief The Worm class operates the behind the scenes of the worm game
 * A developer can move the worm, access the score, manipulate the gameboard elements,
 * and determine if the user has won or lost yet
 */

class Worm : public engine
{
    //! Instance variables
    char gameboard [ROWS][COLS]; // array representing game board
    int biq; // stands for body (segments, o's) in queue
    int len; // the number of o's in the worm's body
    char edge; // the character around the edges
    char empt; // the character for empty spaces
    char body; // the character for the body (o's);
    char head; // the character for the head (@)
    std::pair<int, int> hs; // stands for head start, or starting position of the head
    std::pair<int, int> dir; // stands for direction, or the direction the worm is moving
    std::vector<std::pair<int, int>> segments; // vector of segments of worm
    std::map<int, std::pair<int, int>> blanks; // map of blank spacecs on board

    /*!
     * \brief place lays out the game board
     */
    void place();
    /*!
     * \brief procession moves the worm based on the current direction
     */
    void procession();
    /*!
     * \brief place_points places a character on the gameboard for the worm to gain points
     */
    void place_points(); // stands for place points

    /*!
     * \brief insert_blank inserts on the blank space map a given location
     * \param row the row on the gameboard
     * \param col the column on the gameboard
     */
    void insert_blank(int row, int col); // insert a blank space location on map
    /*!
     * \brief get_rand_blank returns a random blank spot's location
     * \return the row and column of a random blank spot
     */
    std::pair<int, int> get_rand_blank(); // returns the location of a random blank space

public:
    bool won_yet; // true if won, false if have not won yet
    bool lost_yet; // true if lost, false if have not lost yet
    int score; // score of the player
    Worm();
    Worm(int r, int c);
    /*!
     * \brief Worm constructor
     * \param s the random number seed
     */
    Worm(int s); // constructor; configuration is the same in the beginning every time
    /*!
     * \brief insert a char at a given location on the game board
     * \param row the row on the gameboard
     * \param col the column on the game board
     * \param c the character to insert
     * \return
     */
    char insert(int row, int col, char c); // returns char previously at that location
    /*!
     * \brief remove the char at a given location and replace with a blank space
     * \param row the row on the gameboard
     * \param col the column on the gameboard
     * \return the char removed
     */
    char remove(int row, int col); // returns char at that location, replaces with a ' '
    /*!
     * \brief get the char at a location
     * \param row the row on the gameboard
     * \param col the column on the gameboard
     * \return the char at that location
     */
    char get(int row, int col);
    /*!
     * \brief up move the worm up
     */
    void up();
    /*!
     * \brief left move the worm left
     */
    void left();
    /*!
     * \brief down move the worm down
     */
    void down();
    /*!
     * \brief right move the worm right
     */
    void right();
    std::vector<std::pair<int, int>> get_worm();
};

#endif // WORM_H
