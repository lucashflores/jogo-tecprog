#include "Entities/Background.h"
using namespace Entities;

Background::Background(Id::ids id): Ent(id, Coordinates::Vector<float>(1280.f, 720.f), Coordinates::Vector<float>(0.f, 0.f)) {

}

Background::~Background() {

}


void Background::update(Coordinates::Vector<float> pos) {
    sprite->changePosition(pos);
}