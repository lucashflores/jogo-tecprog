#include "Animation.h"

Animation::Animation(std::string pathSpriteSheet, Coordinates::VectorFloat size, sf::Vector2u imageCnt, float switchT)
{
    setGraphicManager(Managers::GraphicManager::getInstance());

    body = sf::RectangleShape(sf::Vector2f(size.getX(), size.getY()));
    texture = pGraphicM->loadTexture(pathSpriteSheet);

    body.setTexture(texture);

    body.setOrigin(sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2));

    this->imageCount = imageCnt;
    this->switchTime = switchT;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x/float(imageCount.x);
    uvRect.height = texture->getSize().y/float(imageCount.y);

    body.setTextureRect(sf::IntRect(0, 0, uvRect.width, uvRect.height));

}

Animation::~Animation() {

}

void Animation::setGraphicManager(Managers::GraphicManager *pGM) {
    if (pGM)
        pGraphicM = pGM;
}

void Animation::render() {
    pGraphicM->render(&body);
}

void Animation::centerViewHere() {
    pGraphicM->centerView(body.getPosition());
}

void Animation::setImageCount(sf::Vector2u imgCnt) {
    imageCount = imgCnt;
}

void Animation::animationUpdate(int row, bool facingLeft, float dt) {

    totalTime += dt;

    if (currentImage.x == imageCount.x || (row != currentRow))
        currentImage.x = 0;


    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
    }

    uvRect.top = row * uvRect.height;
    uvRect.left = currentImage.x * uvRect.width;

    body.setTextureRect(uvRect);

    if (facingLeft)
        body.setScale({-1, 1});
    else
        body.setScale({1, 1});

    currentRow = row;
}

Coordinates::VectorFloat Animation::changePosition(Coordinates::VectorFloat position) {
    body.setPosition(position.getX(), position.getY());
    return Coordinates::VectorFloat(body.getPosition().x, body.getPosition().y);
}