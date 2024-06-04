#pragma once
#include "map.h"
#include <vector>
#include "spaceShip.h"
#include "bullet.h"

class Asteroids {
private:
	int coordX;
	int coordY;
	bool isActive = true;
	int asteroidsCounter = 0;
	int moveCounter = 0;
public:
	void initializeAsteroid();
	void createAsteroid(Map& m, SpaceShip& ship);
	int getAsteroidsCounter() const;
	void increaseAsteroidsCounter();
	void moveAsteroid();
	void checkWallsCollision(SpaceShip& ship);
	void checkShipCollision(SpaceShip& ship);
	void checkBulletCollision();
	
		/*void startAsteroidThread();*/
};
extern std::vector<Asteroids> asteroidsVec;
 
