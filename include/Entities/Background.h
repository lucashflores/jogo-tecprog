#pragma once

#include "Entity.h"

namespace Entities {

    class Background: public Ent {
    public:
        Background(Id::ids id);
        ~Background();
        void update(Coordinates::VectorFloat pos); // CONFERIR DEPOIS!!!!
    };
}