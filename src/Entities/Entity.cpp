#include "Entities/Entity.h"
using namespace Entities;

Entity::Entity(sf::RectangleShape shape, sf::Vector2f pos): body(shape), position(pos) {

}

Entity::~Entity() {
    texture = NULL;
}

sf::Vector2f Entity::getPosition() const {
    return position;
}

void Entity::setTexture(sf::Texture *text) {
    if (text) {
        texture = text;
        body.setTexture(text);
        body.setTextureRect(sf::IntRect (0, 0, 48, 48));
    }
}

void Entity::setGraphicManager(Managers::GraphicManager *pGM) {
    if (pGM)
        pGraphicM = pGM;
}

