#include "spaceShip.h"
#include "constants.h"





void SpaceShip::initializeShip()  {
	lives = 5;
	shipSize = 3;
	coordY = constants::height - 2; 
	coordX = constants::width / 2; 
}


void SpaceShip::drawShip(Map& m) {
	for (int i = coordX; i > coordX - shipSize; --i) {
		m.getMap()[coordY][i] = '&';
	}

}

void SpaceShip::moveShip(int x) {
	if (coordX < shipSize + 1) {
		coordX = shipSize + 1;
	}
	if (coordX + shipSize > constants::width) {
		coordX = constants::width - shipSize;
	}
	coordX += x;

}

int SpaceShip::getCoordX() const {
	return coordX;
}

int SpaceShip::getCoordY() const {
	return coordY;
}

int SpaceShip::getLives() const {
	return lives;
}

void SpaceShip::decreaseLives() {
	--lives;
}

int SpaceShip::getShipSize() const{
	return shipSize;
}