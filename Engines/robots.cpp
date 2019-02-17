#include "robots.h"

/**
 * @brief Robots::Robots constructor, hard coded positions (TESTING ONLY)
 */
Robots::Robots()
{
    robots[0].first = 2;
    robots[0].second = 3;
    robots[1].first = 0;
    robots[1].second = 4;
    robots[2].first = 5;
    robots[2].second = 0;
    player.first = 1;
    player.second = 2;
}

/**
 * @brief Robots::Robots constructor, random positions
 * @param s distingues the two constructors
 */
Robots::Robots(std::string s) {
    std::string t = s;
    robots[0].first = rand() % COLS;
    robots[0].second = rand() % ROWS;
    robots[1].first = rand() % COLS;
    robots[1].second = rand() % ROWS;
    robots[2].first = rand() % COLS;
    robots[2].second = rand() % ROWS;
    player.first = rand() % COLS;
    player.second = rand() % ROWS;
}

/**
 * @brief Robots::~Robots destructor
 */
Robots::~Robots() {

}

/**
 * @brief Robots::movePlayer moves player based on input "n, s, e, w, ne, nw, se, sw, *"
 * @param movement direction
 */
void Robots::movePlayerN() {
    player.second -= 1;
}

void Robots::movePlayerS() {
    player.second += 1;
}

void Robots::movePlayerE() {
    player.first += 1;
}

void Robots::movePlayerW() {
    player.first -= 1;
}

void Robots::movePlayerNE() {
    player.first -= 1;
    player.second -= 1;
}

void Robots::movePlayerNW() {
    player.first += 1;
    player.second -= 1;
}

void Robots::movePlayerSE() {
    player.first -= 1;
    player.second += 1;
}

void Robots::movePlayerSW() {
    player.first += 1;
    player.second += 1;
}


/*
    if(movement.compare("e") || movement.compare("Ne") || movement.compare("se")) {
        //player.first += 1;
    }
    if(movement.compare("w") || movement.compare("Nw") || movement.compare("sw")) {
        //player.first -= 1;
    }
    if(movement.compare("s") || movement.compare("sw") || movement.compare("se")) {
        //player.second += 1;
    }

    else {
        player.first += 0;
    }
    if(player.first == COLS) {
        player.first -= 1;
    }
    if(player.second == ROWS) {
        player.second -= 1;
    }
}


/**
 * @brief Robots::moveRobots based on where the player moved
 */
void Robots::moveRobots() {
    int num_robots = sizeof(robots);
    for(int i = 0; i < num_robots; i++) {
        if(player.first > robots[i].first) {
            robots[i].first += 1;
        }
        if(player.first < robots[i].first) {
            robots[i].first -= 1;
        }
        if(player.second > robots[i].second) {
            robots[i].second += 1;
        }
        if(player.second < robots[i].second) {
            robots[i].second -= 1;
        }
        if(robots[i].first == COLS) {
            robots[i].first -= 1;
        }
        if(robots[i].second == ROWS) {
            robots[i].second -= 1;
        }
    }
}

/**
 * @brief Robots::randomTeleport teleports player to a random position on the grid
 */
void Robots::randomTeleport() {
    player.first = rand() % COLS;
    player.second = rand() % ROWS;
}

/**
 * @brief Robots::isDead determine if 2 robots collided when moved
 * @return T if 2 robots collided, F if none collided
 */
bool Robots::isDead() {
    int num_robots = sizeof(robots);
    for(int i = 0; i < num_robots - 1; i++) {
        if((robots[i].first == robots[i + 1].first) && ((robots[i].second == robots[i + 1].second))) {
            robots[i].first = -1;
            robots[i].second = -1;
            robots[i + 1].first = -1;
            robots[i + 1].second = -1;
            return true;
        }
    }
    return false;
}

/**
 * @brief Robots::win win
 * @return T if win or F is no win
 */
bool Robots::win() {
    int num_robots = sizeof(robots);
    for(int i = 0; i < num_robots; i++) {
        if(robots[i].first != -1 || robots[i].second != -1) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Robots::updateBoard moves pieces on the board after methods have been called
 */
void Robots::updateBoard() {
    int num_robots = sizeof(robots);
    for(int i = 0; i < num_robots; i++) {
        if(robots[i].first != -1 || robots[i].second != -1) {
            gameboard[robots[i].first][robots[i].second] = 'r';
        }
    }
    gameboard[player.first][player.second] = 'h';
}
