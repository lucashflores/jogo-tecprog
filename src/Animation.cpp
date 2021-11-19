#include "Animation.h"

Animation::Animation(std::string pathSpriteSheet, Coordinates::Vector<float> size, Coordinates::Vector<unsigned int> imageCnt, float switchT)
{
    setGraphicManager(Managers::GraphicManager::getInstance());

    body = sf::RectangleShape(sf::Vector2f(size.getX(), size.getY()));
    texture = pGraphicM->loadTexture(pathSpriteSheet);

    body.setTexture(texture);

    body.setOrigin(sf::Vector2f(body.getSize().x / 2.f, body.getSize().y / 2.f));


    imageCount.x = imageCnt.getX();
    imageCount.y = imageCnt.getY();
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

void Animation::render() {
    pGraphicM->render(&body);
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

void Animation::changePosition(Coordinates::Vector<float> position) {
    body.setPosition(position.getX(), position.getY());
}