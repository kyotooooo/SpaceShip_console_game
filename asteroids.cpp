#include "asteroids.h"
#include "randomNumber.h"
#include "constants.h"
#include <iostream>

std::vector<Asteroids> asteroidsVec;

void Asteroids::initializeAsteroid() {
	
	coordX =  getRandomNumber(2,  constants::width - 3);
	coordY = 1; 
	asteroidsVec.push_back(*this);
	
}

int Asteroids::getAsteroidsCounter() const {
    return asteroidsCounter;
}


void Asteroids::increaseAsteroidsCounter() {
    ++asteroidsCounter;
}



void Asteroids::moveAsteroid() {
    for (int i = 0; i < asteroidsVec.size(); ++i) {
        if (asteroidsVec[i].isActive) {
            if (moveCounter == 5) {
                ++asteroidsVec[i].coordY;
                moveCounter = 0;

            }
            ++moveCounter;
        }
    }
    
}

void Asteroids::checkWallsCollision(SpaceShip& ship) {
    for (int i = 0; i < asteroidsVec.size(); ++i) {
        if (asteroidsVec[i].isActive) {

            if (asteroidsVec[i].coordY == constants::height - 1) {
                asteroidsVec[i].isActive = false;
                ship.decreaseLives();
                asteroidsVec.erase(asteroidsVec.begin() + i);
                --i;
                initializeAsteroid();

            }

            
        }
    }
}



void Asteroids::checkBulletCollision() {
    for (int i = 0; i < asteroidsVec.size(); ++i) {
        if (asteroidsVec[i].isActive) {
            for (int j = 0; j < bullets.size(); ++j) {
                if (asteroidsVec[i].coordX == bullets[j].getCoordX() &&
                    asteroidsVec[i].coordY == bullets[j].getCoordY()) {
                    increaseAsteroidsCounter();
                    asteroidsVec[i].isActive = false;

                    initializeAsteroid();

                }
            }
        }
    }
}

void Asteroids::createAsteroid(Map& m, SpaceShip& ship) {
    for (int i = 0; i < asteroidsVec.size(); ++i) {
        if (asteroidsVec[i].isActive) {
                m.getMap()[asteroidsVec[i].coordY][asteroidsVec[i].coordX] = 'A';
        }
    }
}


    