#pragma once
#include "Obstacle.h"

namespace Entities {
    class Fire: public Obstacle {
    private:
        float timer;
    public:
        Fire(Coordinates::Vector<float> pos);

        ~Fire();

        void initializeSprite();

        void setTimer(float time);

        float getTimer();

        void update(float dt);

        void saveEntity(std::ofstream& out) const;
    };
}