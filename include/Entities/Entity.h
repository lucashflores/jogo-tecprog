#pragma once


#include "Ent.h"
#include "Defines/stdafx.h"

namespace Entities {

    class Entity: public Ent {
    protected:

        Coordinates::Vector<float> position;
        Coordinates::Vector<float> hitBox;

        bool isAlive;

        unsigned int damage;

    public:
        Entity(Id::ids i, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos);

        virtual ~Entity() = 0;

        void setPosition(Coordinates::Vector<float> pos);

        const Coordinates::Vector<float> getPosition() const;

        const Coordinates::Vector<float> getHitBox() const;

        void setDamage(unsigned int dmg);

        unsigned int getDamage() const;

        virtual void neutralize();

        bool getIsAlive();

        virtual void update(float dt) = 0;

        void saveEntityInfo(std::ofstream& out) const;

        virtual void saveEntity(std::ofstream& out) const = 0;
    };

}