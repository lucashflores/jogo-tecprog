#include "States/NewStage2State.h"
using namespace States;

NewStage2State::NewStage2State(Entities::Player* p1, Entities::Player* p2) {
    exec(p1, p2);
}

NewStage2State::~NewStage2State() {}

void NewStage2State::exec(Entities::Player* p1, Entities::Player* p2) {
    Stages::Stage2Factory* stage2Factory = new Stages::Stage2Factory();
    Stages::Stage* stage = stage2Factory->requestStage(p1, p2);
}
