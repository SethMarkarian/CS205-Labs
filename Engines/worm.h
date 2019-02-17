#ifndef WORM_H
#define WORM_H
#include <iostream>
#include <vector>
#define ROWS 5
#define COLS 5 //I just can't start with 3 columns. there's an edge rn.
#include <stdlib.h>
#include <map>
#include <functional>
#include <thread>

class Worm
{
    char gameboard [ROWS][COLS];
    int biq; // stands for body (o's) in queue
    int len; // the number of o's in the worm's body
    char edge; // the character around the edges
    char empt; // the character for empty spaces
    char body; // the character for the body (o's);
    char head; // the character for the head (@)
    std::pair<int, int> hs; // stands for head start, or starting position of the head
    std::pair<int, int> dir; // stands for direction start, or the direction the worm starts in
    std::vector<std::pair<int, int>> segments; // vector of segments of worm
    void place(); // lays out the game board
    char insert(int x, int y, char c); // returns char previously at that location
    char remove(int a, int b); // returns char at that location, replaces with a ' '
    std::pair<char, char> move(int a, int b, int x, int y); // returns pair of <character moved, character removed>
    void procession(); //must be + or - (1, 0) or (0, 1)
    void place_points(); // stands for place points
    int seed; // random number seed
    std::map<int, std::pair<int, int>> blanks; // map of blank spacecs on board
    void insert_blank(int x, int y); // insert a blank space location on map
    std::pair<int, int> get_rand_blank(); // returns the location of a random blank space
    // void timer_start(std::function fun, unsigned int interval);
    // void do_something();

public:
    bool won_yet;
    bool lost_yet;
    int score;
    Worm();
    void up();
    void left();
    void down();
    void right();
    // int main();
};

#endif // WORM_H
