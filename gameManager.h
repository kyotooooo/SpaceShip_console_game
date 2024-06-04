#include <iostream>
#include "map.h" 
#include "cursor.h"
#include "constants.h"
#include "spaceShip.h"
#include "gun.h"
#include "bullet.h"
#include "asteroids.h"
#include <ctime> 
#include <Windows.h>
#include "timer.h"

class GameManager {
private:
	Map m;
	SpaceShip ship;
	Gun gun;
	Bullet bull;
	Asteroids asteroid;
	Timer timer;
	bool hasLose;
public:
	GameManager(int heiht, int width);
	void runGame();
	void renderGame();
	void handleInput();
	void updateGame();
	void checkCollision();
};