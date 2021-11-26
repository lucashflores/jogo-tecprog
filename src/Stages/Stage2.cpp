#include "Stages/Stage2.h"
using namespace Stages;

Stage2::Stage2(EntityList *pEL, Entities::Player *player1, Entities::Player *player2):
Stage(pEL, player1, player2)
{
    background = new Background(Id::background2);
    Coordinates::Vector<float> initialPos = Coordinates::Vector<float>(INITIALPOS_X, INITIALPOST_Y);
    player1->setPosition(initialPos);
    if (player2)
        player2->setPosition(initialPos);
}

Stage2::~Stage2() {

}
