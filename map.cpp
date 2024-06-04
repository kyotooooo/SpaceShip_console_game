#include <iostream>
#include "map.h"
#include "spaceShip.h"
#include "timer.h"
#include "asteroids.h"


Map::Map(int y, int x) : height(y), width(x) {
    map = new char* [height];
    for (int i = 0; i < height; ++i) {
        map[i] = new char[width];
    }

}



Map::~Map() {
    for (int i = 0; i < height; ++i) {
        delete[] map[i];
    }
    delete[] map;
    map = nullptr;
}

void Map::initializeMap() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                map[i][j] = '#';
            }
            else {
                map[i][j] = ' ';
            }
        }
    }
}

void Map::showMap(SpaceShip& ship, Timer& timer,Asteroids& asteroid) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << map[i][j];
            if (i == 3 && j == width - 1) {
                std::cout << "\t Elapsed Time: " << timer.elapsed() << " seconds";
            }
            if (i == 4 && j == width - 1) {
                std::cout << "\t Lives: " << ship.getLives();
            }
            if (i == 5 && j == width - 1) {
                std::cout << "\t Asteroids destroyed: " << asteroid.getAsteroidsCounter();
            }
        }
        std::cout << std::endl;
    }
}

char** Map::getMap() const{
    return map;
}
