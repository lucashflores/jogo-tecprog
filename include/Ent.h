#pragma once

#include "Defines/objectsafx.h"
#include "TEXTURE_PATHS.h"
#include "Animation.h"
#include "Id.h"

class Ent {
protected:
    const Id::ids id;
    Animation* sprite;
public:
    Ent(Id::ids i, Coordinates::Vector<float> size, Coordinates::Vector<float> pos);
    virtual ~Ent();
    const Id::ids getId() const;
    void render();
};