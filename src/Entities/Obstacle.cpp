#include "Entities/Obstacle.h"
using namespace Entities;

Obstacle::Obstacle(sf::Vector2f pos, unsigned char d):
Entity(Id::obstacle, sf::RectangleShape(sf::Vector2f(32.f, 32.f)), pos), damage(d)  {
    this->setTexture(pGraphicM->loadTexture("../assets/tile.png"));
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
}

Obstacle::~Obstacle() {
}

sf::FloatRect Obstacle::getHitBox() {
    sf::FloatRect rect = body.getGlobalBounds();
    return rect;
}

void Obstacle::collide(Entity* pE) {
    return;
}




