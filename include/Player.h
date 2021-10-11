#pragma once

#include "Entities.h"
#include "InputManager.h"
#include "GraphicManager.h"

class Player: public Entities {
private:
    InputManager* inputInstance;
    GraphicManager* graphicInstance;
public:
    Player(float velocity, unsigned char life, sf::Texture sprite);
    ~Player();
    void setGraphicInstance(GraphicManager* instance);
    void setInputInstance(InputManager* instance);
    void move();

};