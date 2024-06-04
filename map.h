#pragma once
#include "timer.h"
#include <memory>
class SpaceShip;
class Asteroids;

class Map {
private:
	 int height;
	 int width;
	char** map;
	
public:
	Map(const int y, const int x);
	~Map();
	void initializeMap();
	void showMap( SpaceShip& ship, Timer& timer,  Asteroids& asteroid);
	char** getMap() const;

};