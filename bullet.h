#pragma once
#include <vector>
#include "gun.h"
#include "asteroids.h"

class Bullet {
private:
	int coordX;
	int coordY;
	bool isActive = true;	
public:
	void shoot(Gun& g);
	void updateBullets(Map& m);
	int getCoordX() const;
	int getCoordY() const;
};

extern std::vector<Bullet> bullets;