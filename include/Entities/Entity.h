#pragma once


#include "Coordinates/VectorFloat.h"
#include "Ent.h"



namespace Entities {

    class EntityList;

    class Entity: public Ent {
    protected:
        Id::ids id;
        Coordinates::VectorFloat position;
        EntityList* pEntityList;
        Coordinates::VectorFloat hitBox;
    public:
        Entity(Coordinates::VectorFloat hit, Coordinates::VectorFloat pos);

        virtual ~Entity();

        void setPosition(Coordinates::VectorFloat pos);

        Coordinates::VectorFloat getPosition() const;

        Coordinates::VectorFloat getHitBox();

        virtual void collide(Entity* pE) = 0;

        void move(Coordinates::VectorFloat pos);
    };

}