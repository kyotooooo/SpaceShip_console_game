#include "gameManager.h"

GameManager::GameManager(int height, int width) : m(height, width), hasLose(false) {};

void GameManager::runGame() {
    hideCursor();
    srand(static_cast<unsigned int>(time(0)));
    gun.initializeGun();
    ship.initializeShip();
    asteroid.initializeAsteroid();
    while (!hasLose) {
        if (ship.getLives() < 1) {
            hasLose = true;
        }
        if (asteroid.getAsteroidsCounter() > 20) {
            system("cls");
            std::cout << "\t\t\tCongratulations, you WIN!";
            break;
        }
        updateGame();
        handleInput();
        renderGame();
        checkCollision();
    }
}

void GameManager::handleInput() {
    if (GetAsyncKeyState((unsigned short)'A') < 0) ship.moveShip(-1);
    if (GetAsyncKeyState((unsigned short)'D') < 0) ship.moveShip(1);
    if (GetAsyncKeyState(VK_SPACE) < 0) bull.shoot(gun);
    if (GetAsyncKeyState(VK_ESCAPE) < 0) exit(0);
}

void GameManager::updateGame() {
    gun.moveGun(ship.getCoordX() - 1, ship.getCoordY() - 1);
    m.initializeMap();
    ship.drawShip(m);
    gun.drawGun(m);
    bull.updateBullets(m);
    asteroid.moveAsteroid();
    asteroid.createAsteroid(m, ship);
}
void GameManager::renderGame() {
    m.showMap(ship, timer, asteroid);
    setCursorPosition(0, 0);
}

void GameManager::checkCollision() {
    asteroid.checkWallsCollision(ship);

    asteroid.checkBulletCollision();
}