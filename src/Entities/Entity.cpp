#include "Entities/Entity.h"
#include "EntityList.h"
using namespace Entities;

Entity::Entity(Id::ids i, sf::RectangleShape shape, Coordinates::VectorFloat hit, Coordinates::VectorFloat pos):
id(i), body(shape), hitBox(hit), position(pos) {
    position = pos;
    pEntityList = EntityList::getInstance();
    body.setPosition(pos);
    body.setOrigin(body.getSize().x/2, body.getSize().y/2);
    pEntityList->addEntity(this);
    pGraphicM = Managers::GraphicManager::getInstance();
}



Entity::~Entity() {
    texture = NULL;
    pGraphicM = NULL;
}

Id::ids Entity::getId() {
    return id;
}

void Entity::setPosition(sf::Vector2f pos) {
    position = pos;
    body.setPosition(position);
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

void Entity::setTextureRect(sf::IntRect rect) {
    body.setTextureRect(rect);
}


sf::FloatRect Entity::getHitBox() {
    sf::FloatRect rect = body.getGlobalBounds();
    return rect;
}

void Entity::move(sf::Vector2f pos) {
    body.move(pos);
    position= body.getPosition();
}

void Entity::render() {
    pGraphicM->render(&body);
}