#include "Entities/Entity.h"
#include "EntityList.h"
using namespace Entities;

Entity::Entity(Coordinates::VectorFloat hit, Coordinates::VectorFloat pos):
hitBox(hit), position(pos) {
    position = pos;
    pEntityList = EntityList::getInstance();
    pEntityList->addEntity(this);
}



Entity::~Entity() {
}

Id::ids Entity::getId() {
    return id;
}

void Entity::setPosition(Coordinates::VectorFloat pos) {
    position = pos;
}

Coordinates::VectorFloat Entity::getPosition() const {
    return position;
}

void Entity::setTexture(sf::Texture *text) {
    if (text) {
        texture = text;
        body.setTexture(text);
        body.setTextureRect(sf::IntRect (0, 0, 48, 48));
    }
}

void Entity::setTextureRect(sf::IntRect rect) {
    body.setTextureRect(rect);
}


Coordinates::VectorFloat Entity::getHitBox() {
    return hitBox;
}

void Entity::move(Coordinates::VectorFloat pos) {
    position.setX(position.getX() + pos.getX());
}

void Entity::render() {
    pGraphicM->render(&body);
}