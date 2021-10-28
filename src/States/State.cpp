#include "States/State.h"
#include "States/StateMachine.h"
using namespace States;

State::State() {
    pStateM = NULL;
}

State::~State() {
    pStateM = NULL;
}

void State::setStateMachine(StateMachine *pSM) {
    if (pSM)
        pStateM = pSM;
}

void State::changeState(std::string stateName) {
    pStateM->setCurrentState(stateName);
}
