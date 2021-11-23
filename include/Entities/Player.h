#pragma once


#include "Defines/playerafx.h"


#include "Entities/Character.h"
#include "Managers/InputManager.h"

class PlayerControl;

namespace Entities {

    class Player : public Character {
    private:
        PlayerControl* playerControl;
        bool isPlayerOne;

    public:
        Player(bool isPlayerOne=true);

        ~Player();

        void walk(bool left);

        void jump();

        void attack(Character* pChar) override;

        void initializeSprite();

        //void collide(Entity* pE, Coordinates::Vector<float> collision);

        void update(float dt) override;

        void saveEntity(std::ofstream& out);

        void restoreEntity(std::ifstream& in);
    };

}