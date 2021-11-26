#include "Entities/Projectile.h"
#include <iostream>
#include <fstream>

using namespace Entities;

Projectile::Projectile(Coordinates::Vector<float> pos, bool isFL):
        Entity(Id::projectile, Coordinates::Vector<float>(10.0f, 10.0f), pos),
        velocity(0.f,0.f),
        timer(0) {

    setDamage(2);
    isFacingLeft = isFL;
    (isFacingLeft)?(velocity.setX(-200.f)):(velocity.setX(200.f));
    initializeSprite();

}

Projectile::~Projectile() {

}


void Projectile::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(1, 1);
    Coordinates::Vector<float> size = Coordinates::Vector<float>(20.f, 20.f);
    sprite = new Animation(FIREBALL_TEXTURE_PATH, size, imageCnt,1.f);
    sprite->changePosition(position);
}

void Projectile::update(float dt) {
    sprite->animationUpdate(0, isFacingLeft, dt);
    setPosition(Coordinates::Vector<float>(getPosition().getX() + velocity.getX()*dt,getPosition().getY()+ velocity.getY()*dt));
    sprite->changePosition(position);
    timer += dt;
    if(timer>5.f){eliminate(); std::cout << "Tchau projétil" << std::endl;}
}

void Projectile::saveEntity(std::ofstream& out) const{
    saveEntityInfo(out);

    out <<
        isFacingLeft << " " <<
        velocity.getX() << " " <<
        velocity.getY() << "\n";
}