#include "Background.h"
using namespace Entities;

Background::Background(Id::ids id): Ent(id) {
    initializeSprite();
}

Background::~Background() {

}

void Background::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(1, 1);
    Coordinates::Vector<float> size= Coordinates::Vector<float>(1280.f, 720.f);

    if(getId() == Id::background1){
        sprite = new Animation(BACKGROUND1_TEXTURE_PATH, size, imageCnt,1.f);
    }
    else if(getId() == Id::background2) {
        sprite = new Animation(BACKGROUND2_TEXTURE_PATH, size, imageCnt, 1.f);
    }
    else if(getId() == Id::menuBackground) {
        sprite = new Animation(BACKGROUND3_TEXTURE_PATH, size, imageCnt, 1.f);
    }

}

void Background::update(Coordinates::Vector<float> pos) {
    sprite->changePosition(pos);
}