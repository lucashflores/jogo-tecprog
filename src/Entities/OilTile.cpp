#include "Entities/OilTile.h"
using namespace Entities;

OilTile::OilTile(Coordinates::Vector<float> pos): Tile(Id::oilTile, pos) {
    initializeSprite();
}

OilTile::~OilTile() {}
<<<<<<< HEAD
=======

void OilTile::initializeSprite() {
    Coordinates::Vector<unsigned int> imageCnt = Coordinates::Vector<unsigned int>(1, 1);

    Coordinates::Vector<float> size = Coordinates::Vector<float>(32.f, 32.f);

    sprite = new Animation(OIL_TILE_TEXTURE_PATH, size, imageCnt, 1.f);

    sprite->changePosition(position);
}

void OilTile::saveEntity(std::ofstream& out) {
    saveEntityInfo(out);
}

void OilTile::restoreEntity(std::ifstream& in) {
    float velocityX, velocityY;

    try{
        restoreEntity(in);
    }

    catch (std::invalid_argument e){
        std::cerr << "Error: Could not load Projectile!" << std::endl;
    }
}
>>>>>>> 765ea23d113b3e3f487d8ce05effd29b43c74d28
