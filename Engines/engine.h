#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>


class engine
{
protected:
    int rows;
    int cols;

public:
    char ** gameboard; // who knows how to use this??
    engine(int r, int c);
    engine();
    ~engine();
};

#endif // ENGINE_H
