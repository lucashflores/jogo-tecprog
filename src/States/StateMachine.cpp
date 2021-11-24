#include "States/StateMachine.h"
#include "States/State.h"

using namespace States;

StateMachine::StateMachine() {
    currentState = NULL;
}

StateMachine::~StateMachine() {
    currentState = NULL;
    State* paux = NULL;
    for (auto it = stateList.begin(); it != stateList.end(); it++)
        paux = (it->second);
        if (paux)
            delete paux;
        paux = NULL;
    stateList.clear();
}

void StateMachine::setCurrentState(std::string stateName) {
    currentState = stateList.at(stateName);
    currentState->reset();
}

State *StateMachine::getCurrentState() {
    return currentState;
}

void StateMachine::updateCurrentState(float dt) {
    if (currentState)
        currentState->update(dt);
}