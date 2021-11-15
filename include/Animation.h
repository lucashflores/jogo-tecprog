#pragma once

#include "Managers/GraphicManager.h"
#include "Coordinates/VectorTemplate.h"

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
    Animation(std::string pathSpriteSheet, Coordinates::Vector<float> size, Coordinates::Vector<unsigned int> imageCnt, float switchT);

    ~Animation();

    void setGraphicManager(Managers::GraphicManager* pGM);

    void render();

    void centerViewHere(); // MUDAR!!!!

    void setImageCount(sf::Vector2u imgCnt);

    void animationUpdate(int row, bool facingLeft, float dt);

    void changePosition(Coordinates::Vector<float> position);



};
