#include "Entities/Entity.h"
#include "Entities/EntityList.h"
using namespace Entities;

Entity::Entity(Id::ids i, sf::RectangleShape shape, sf::Vector2f pos): id(i), body(shape), position(pos) {
    pEntityList = EntityList::getInstance();
    body.setPosition(pos);
    pEntityList->addEntity(this);
    setGraphicManager(Managers::GraphicManager::getInstance());
}



Entity::~Entity() {
    texture = NULL;
    pGraphicM = NULL;
    pEventM = NULL;
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

void Entity::setGraphicManager(Managers::GraphicManager *pGM) {
    if (pGM)
        pGraphicM = pGM;
}

sf::FloatRect Entity::getHitBox() {
    return body.getGlobalBounds();
}

void Entity::move(sf::Vector2f p) {
    body.move(p);
    position= body.getPosition();
}

void Entity::render() {
    pGraphicM->render(&body);
}