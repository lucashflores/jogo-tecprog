#pragma once

#include "TEXTURE_PATHS.h"
#include "Animation.h"
#include "Id.h"

class Ent {
protected:
    const Id::ids id;
    Animation* sprite;
public:
    Ent(Id::ids i, Coordinates::VectorFloat size, Coordinates::VectorFloat pos);
    virtual ~Ent();
    const Id::ids getId() const;
    void render();
};