#include "Player.h"

Player::Player(float velocity, unsigned char life): Entities(velocity, life) {
    graphicInstance = NULL;
    inputInstance = NULL;
}

Player::~Player() {
    graphicInstance = NULL;
    inputInstance = NULL;
}

void Player::setGraphicInstance(GraphicManager *instance) {
    graphicInstance = instance;
}

void Player::setInputInstance(GraphicManager *instance) {
    inputInstance = instance;
}

void Player::move() {

}