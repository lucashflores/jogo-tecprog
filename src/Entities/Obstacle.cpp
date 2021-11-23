#include "Entities/Obstacle.h"
using namespace Entities;


Obstacle::Obstacle(Id::ids i, Coordinates::Vector<float> hit, Coordinates::Vector<float> pos, unsigned int d):
Entity(i, hit, pos) {
    setDamage(d);
}

Obstacle::~Obstacle() {
}

void Obstacle::update(float dt) {
    sprite->animationUpdate(0, false ,0.f);
}

unsigned int Obstacle::getDamage() {
    return damage;
}

void Obstacle::saveEntity(std::ofstream& out) {
    saveEntityInfo(out);
}

void Obstacle::restoreEntity(std::ifstream& in) {
    try{
        restoreEntity(in);
    }

    catch (std::invalid_argument e){
        std::cerr << "Error: Could not load Projectile!" << std::endl;
    }
}