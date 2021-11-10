#pragma once

#include "Managers/GraphicManager.h"

class Animation {
private:
    Managers::GraphicManager* pGraphicM;

    sf::RectangleShape body;
    sf::Texture* texture;

    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    sf::IntRect uvRect;

    float totalTime;
    float switchTime;

public:
    Animation(const char* pathSpriteSheet, sf::RectangleShape shape, sf::Vector2u imageCnt, float switchT);
    ~Animation();
    void setGraphicManager(Managers::GraphicManager* pGM);
    void setTexture(const char* path);
    void setImageCount(sf::Vector2u imgCnt);
    void animationUpdate(int row, bool facingLeft, sf::Vector2f position, float dt);


};
