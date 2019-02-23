#include "robots.h"

/**
 * @brief Robots::Robots constructor, hard coded positions (TESTING ONLY)
 */
Robots::Robots() : engine(10, 6)
{
    robots[0].first = 4;
    robots[0].second = 6;
    robots[1].first = 0;
    robots[1].second = 8;
    robots[2].first = 10;
    robots[2].second = 0;
    robots[3].first = 5;
    robots[3].second = 0;
    player.first = 2;
    player.second = 4;
}

/**
 * @brief Robots::Robots constructor, random positions
 * @param s distingues the two constructors
 */
Robots::Robots(int r, int c) : engine(r, c){
    robots[0].first = rand() % cols;
    robots[0].second = rand() % rows;
    robots[1].first = rand() % cols;
    robots[1].second = rand() % rows;
    robots[2].first = rand() % cols;
    robots[2].second = rand() % rows;
    robots[3].first = rand() % cols;
    robots[3].second = rand() % rows;
    player.first = rand() % cols;
    player.second = rand() % rows;
}

/**
 * @brief Robots::~Robots destructor
 */
Robots::~Robots() {

}

/**
 * @brief Robots::movePlayer moves player
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
        if(robots[i].first == rows) {
            robots[i].first -= 1;
        }
        if(robots[i].second == cols) {
            robots[i].second -= 1;
        }
    }
}

/**
 * @brief Robots::randomTeleport teleports player to a random position on the grid
 */
void Robots::randomTeleport() {
    player.first = rand() % cols;
    player.second = rand() % rows;
}

/**
 * @brief Robots::isDead determine if 2 robots collided when moved
 * @return T if 2 robots collided, F if none collided
 */
void Robots::isDead() {
    int num_robots = sizeof(robots);
    for(int i = 0; i < num_robots; i++) {
        for(int j = i + 1; j < num_robots; j++) {
            if((robots[i].first == robots[j].first) && ((robots[i].second == robots[j].second))) {
                robots[i].first = -1;
                robots[i].second = -1;
                robots[j].first = -1;
                robots[j].second = -1;
            }
        }

    }
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
        if(robots[i].first != -1 && robots[i].second != -1) {
            engine::gameboard[robots[i].first][robots[i].second] = 'r';
        }
    }
    engine::gameboard[player.first][player.second] = 'h';
}

int Robots::getRows() {
   return rows;
}

int Robots::getCols() {
    return cols;
}

bool Robots::playerDead() {
    int num_robots = sizeof(robots);
    for(int i = 0; i < num_robots - 1; i++) {
        if((robots[i].first == player.first) && ((robots[i].second == player.second))) {
            return true;
        }
    }
    return false;
}

char Robots::get(int row, int col) {
    return engine::gameboard[row][col];
}
