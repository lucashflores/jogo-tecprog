#include "Stages/Stage1.h"
using namespace Stages;

Stage1::Stage1(EntityList *pEL, Entities::Player *player1, Entities::Player *player2):
Stage(pEL, player1, player2)
{
    background = new Background(Id::background1);
    Coordinates::Vector<float> initialPos = Coordinates::Vector<float>(INITIALPOS_X, INITIALPOST_Y);
    player1->setPosition(initialPos);
    if (player2)
        player2->setPosition(initialPos);

}

Stage1::~Stage1() {
}
