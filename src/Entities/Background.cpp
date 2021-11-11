#include "Entities/Background.h"
using namespace Entities;

Background::Background(Id::ids id): Ent(id, Coordinates::VectorFloat(1280.f, 720.f), Coordinates::VectorFloat(0.f, 0.f)) {

}

Background::~Background() {

}


void Background::update(Coordinates::VectorFloat pos) {
    sprite->changePosition(pos);
}