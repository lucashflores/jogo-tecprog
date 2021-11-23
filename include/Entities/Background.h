#pragma once

#include "Entity.h"
#include "Defines/backgroundafx.h"

namespace Entities {

    class Background: public Ent {
    public:
        Background(Id::ids id);

        ~Background();

        void initializeSprite();

        void update(Coordinates::Vector<float> pos); // CONFERIR DEPOIS!!!!
    };
}