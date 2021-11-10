#include "Animation.h"

Animation::Animation(const char* pathSpriteSheet, sf::RectangleShape shape, sf::Vector2u imageCnt, float switchT)
{
    setGraphicManager(Managers::GraphicManager::getInstance());

    body = shape;
    texture = pGraphicM->loadTexture(pathSpriteSheet);

    body.setOrigin(sf::Vector2f(shape.getSize().x / 2, shape.getSize().y / 2));

    this->imageCount = imageCnt;
    this->switchTime = switchT;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x/float(imageCount.x);
    uvRect.height = texture->getSize().y/float(imageCount.y);

}

Animation::~Animation() {

}

void Animation::setGraphicManager(Managers::GraphicManager *pGM) {
    if (pGM)
        pGraphicM = pGM;
}

void Animation::setTexture(const char *path) {
    texture = pGraphicM->loadTexture(path);
    currentImage.x = 0;
}

void Animation::setImageCount(sf::Vector2u imgCnt) {
    imageCount = imgCnt;
}

void Animation::animationUpdate(float dt) {
    totalTime += dt;

    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;
    }

    if (currentImage.x == imageCount.x)
        currentImage.x = 0;

    uvRect.left = currentImage.x * uvRect.width;
    if (body->getTexture() != texture)
        body->setTexture(texture);
    body->setTextureRect(uvRect);


}
