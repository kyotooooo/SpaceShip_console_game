#include "bullet.h"
#include "asteroids.h" 

std::vector<Bullet> bullets;

int Bullet::getCoordX() const{
    return coordX;
}

int Bullet::getCoordY() const {
    return coordY;
}

void Bullet::shoot(Gun& g) {
    coordX = g.getCoordX();
    coordY = g.getCoordY() - 1;
    bullets.push_back(*this);
}

void Bullet::updateBullets(Map& m) {
    for (int i = 0; i < bullets.size(); ++i) {
        if (bullets[i].isActive) {
            m.getMap()[bullets[i].coordY][bullets[i].coordX] = '*';
            --bullets[i].coordY;
        } 
        if (bullets[i].coordY < 1) {
            bullets[i].isActive = false;
            bullets.erase(bullets.begin() + i);
            --i;
        }  
    }
}
