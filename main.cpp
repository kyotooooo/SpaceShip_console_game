#include "gameManager.h"
#include "constants.h"


int main() {
	GameManager gameManager(constants::height, constants::width);
	gameManager.runGame();
}

