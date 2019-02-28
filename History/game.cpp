#include "game.h"

Game::Game()
{

}

Game::Game(Player *p)
{
    pl = p;
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
