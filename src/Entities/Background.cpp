#include "Entities/Background.h"
using namespace Entities;

Background::Background(Id::ids id): Entity(id, sf::RectangleShape(sf::Vector2f(1280.f, 720.f)), sf::Vector2f(0.f, 0.f)) {
    if (id == Id::background1) {
        setTexture(pGraphicM->loadTexture("./assets/background.png"));
        setTextureRect(sf::IntRect(0, 0, 576, 324));
    }
}

Background::~Background() {

}

void Background::collide(Entity* pE) {
    return;
}

void Background::update(sf::Vector2f pos) {
    setPosition(pos);
}