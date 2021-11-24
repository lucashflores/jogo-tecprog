#pragma once

#include "StateMachine.h"
#include <string>
#include <map>

namespace States {
    class State;

    class StateMachine {
    protected:
        std::map<std::string, State*> stateList;
        State* currentState;
    public:
        StateMachine();
        virtual ~StateMachine();
        void setCurrentState(std::string stateName);
        State* getCurrentState();
        void updateCurrentState(float dt);
    };

}