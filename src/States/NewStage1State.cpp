#include "States/NewStage1State.h"
using namespace States;

NewStage1State::NewStage1State(Entities::Player* p1, Entities::Player* p2) {
    exec(p1, p2);
}

NewStage1State::~NewStage1State() {}

void NewStage1State::exec(Entities::Player* p1, Entities::Player* p2) {
    Stages::Stage1Factory* stage1Factory = new Stages::Stage1Factory();
    Stages::Stage* stage = stage1Factory->requestStage(p1, p2);
}
