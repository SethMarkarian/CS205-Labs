#include "engine.h"

engine::engine()
{
    rows = 4;
    cols = 4;

    // Allocation
    gameboard = new char*[rows];
    for(int i = 0; i < rows; i++) {
        gameboard[i] = new char[cols];
    }

    // Initialization
    for(int j = 0; j < rows; j++) {
        for(int i = 0; i < rows; i++) {
            gameboard[i][j] = ' ';
        }
    }

    std::cout << "\n" << gameboard[2][1];

}
engine::engine(int r, int c)
{
    rows = r;
    cols = c;

    // Allocation
    gameboard = new char*[rows];
    for(int i = 0; i < rows; i++) {
        gameboard[i] = new char[cols];
    }

    // Initialization
    for(int j = 0; j < rows; j++) {
        for(int i = 0; i < rows; i++) {
            gameboard[i][j] = '_';
        }
    }

    std::cout << "\n" << gameboard[2][1];
}

engine::~engine() {
    for(int i = 0; i < rows; i++) {
        delete[] gameboard[i];
    }
    delete[] gameboard;
}
