#include "game.h"

Game::Game()
{

}

Game::Game(Player *p, char * n, int f)
{
    pl = p;
    name = n;
    fs = f;
}

Game::~Game() {

}

Player Game::getPlayer() {
    return *pl;
}

char Game::getName() {
    return *name;
}

int Game::getFinalScore() {
    return fs;
}
