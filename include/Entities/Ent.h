#pragma once

#include "Animation.h"
#include "Id.h"

class Ent {
protected:
    Animation* sprite;
public:
    Ent(const char* texturePath, sf::RectangleShape shape);
    virtual ~Ent();
    Id::ids getId();
    virtual void update(float dt) = 0;
    void render();
};