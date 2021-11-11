#pragma once

#include "Managers/GraphicManager.h"
#include "Coordinates/VectorFloat.h"

class Animation {
private:
    Managers::GraphicManager* pGraphicM;

    sf::RectangleShape body;
    sf::Texture* texture;

    int currentRow;

    sf::Vector2u imageCount;
    sf::Vector2u currentImage;
    sf::IntRect uvRect;

    float totalTime;
    float switchTime;

public:
    Animation(std::string pathSpriteSheet, Coordinates::VectorFloat size, sf::Vector2u imageCnt, float switchT);
    ~Animation();
    void setGraphicManager(Managers::GraphicManager* pGM);
    void render();
    void centerViewHere(); // MUDAR!!!!
    void setImageCount(sf::Vector2u imgCnt);
    void animationUpdate(int row, bool facingLeft, float dt);
    Coordinates::VectorFloat changePosition(Coordinates::VectorFloat position);


};
