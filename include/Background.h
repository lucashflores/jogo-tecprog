#pragma once

#include "Entities/Entity.h"
#include "Defines/backgroundafx.h"


class Background: public Ent {
public:
    Background(Id::ids id);
    ~Background();
    void initializeSprite();
    void update(Coordinates::Vector<float> pos); // CONFERIR DEPOIS!!!!
};