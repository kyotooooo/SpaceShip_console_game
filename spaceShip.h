#pragma once
#include "map.h"


class SpaceShip {
private:
	int coordX;
	int coordY;
	int shipSize;
	int lives;
public: 
	void initializeShip() ;
	void drawShip(Map& m) ;
	void moveShip(int x);
	int getCoordX() const;
	int getCoordY() const;
	int getLives() const;
	void decreaseLives();
	int getShipSize() const;

};