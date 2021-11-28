#pragma once

#include "Entities/Entity.h"

namespace Entities {

    class Character: public Entity {
    protected:

        Coordinates::Vector<float> velocity;
        float velocityCoefficient;
        unsigned int life;
        bool isFacingLeft;
        bool isWalking;
        bool isOnGround;
        bool isAttacking;
        float attackTimer;

    public:
        Character(Id::ids i, unsigned int l, unsigned int d, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos);

        virtual ~Character();

        void setVelocityCoefficient(float c);

        void setVelocity(Coordinates::Vector<float> v);

        Coordinates::Vector<float> getVelocity() const;

        void neutralize();

        void setLife(int l);

        int getLife() const;

        void setIsFacingLeft(bool facingLeft);

        void setIsWalking(bool walking);

        void setIsOnGround(bool isOnGround);

        void setIsAttacking(bool attacking);

        bool getIsAttacking();

        void setAttackTimer(float time);

        float getAttackTimer();

        virtual void attack(Character* pChar) = 0;

        virtual void update(float dt) = 0;

        virtual void saveEntity(std::ofstream& out) const = 0;
    };
}