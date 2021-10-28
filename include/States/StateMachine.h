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
        ~StateMachine();
        void setCurrentState(std::string stateName);
        State* getCurrentState();
    };

}