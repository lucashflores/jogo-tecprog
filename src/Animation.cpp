#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCnt, float switchT)
{
    this->imageCount = imageCnt;
    this->switchTime = switchT;
    totalTime = 0.0f;
    currentImage.x = 0;

    uvRect.width = texture->getSize().x/float(imageCount.x);
    uvRect.height = texture->getSize().y/float(imageCount.y);
}

Animation::~Animation() {

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

}
