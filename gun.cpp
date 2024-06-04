#include "gun.h"
#include "constants.h"
#include "map.h"

void Gun::initializeGun() {
	coordX = (constants::width / 2) - 1;
	coordY = constants::height - 3;
}


void Gun::drawGun(Map& m) {
	m.getMap()[coordY][coordX] = 'T';
}

void Gun::moveGun(int x, int y) {
	coordX = x;
	coordY = y;
}

int Gun::getCoordX() const {
	return coordX;
}

int Gun::getCoordY() const {
	return coordY;
}

