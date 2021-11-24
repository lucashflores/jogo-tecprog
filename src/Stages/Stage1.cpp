#include "Stages/Stage1.h"
using namespace Stages;

Stage1::Stage1(EntityList *pEL, Entities::Player *player1, Entities::Player *player2):
Stage(pEL, player1, player2)
{
    background = new Background(Id::background1);
}

Stage1::~Stage1() {
}
/*
int Stage::getStageNumber() {
    return 1;
}
 */