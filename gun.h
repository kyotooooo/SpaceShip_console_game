#pragma once

#include "map.h"
class Gun {
private:
	int coordX;
	int coordY;
public:
	void initializeGun();
	void drawGun(Map& m);
	void moveGun(int x, int y);
	int getCoordX() const;
	int getCoordY() const;
	
};