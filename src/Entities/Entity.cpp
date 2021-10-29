#include "Entities/Entity.h"
using namespace Entities;

Entity::Entity(sf::RectangleShape shape, sf::Texture *text, sf::Vector2f pos, sf::Vector2f v) {
    body = shape;
    if (text) {
        texture = text;
        body.setTexture(text);
        body.setTextureRect(sf::IntRect (0, 0, 48, 48));
    }
    position = pos;
    velocity = v;
    animation = NULL;
}

Entity::~Entity() {
    texture = NULL;
    animation = NULL;
}

sf::Vector2f Entity::getPosition() {
    return position;
}

void Entity::setGraphicManager(Managers::GraphicManager *pGM) {
    if (pGM)
        pGraphicM = pGM;
}


void Entity::setEventManager(Managers::EventManager *pEM) {
    if (pEM)
        pEventM = pEM;
}

