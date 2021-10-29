#pragma once

#include "StateMachine.h"
#include "State.h"


namespace States {

    class State {
    private:
        StateMachine* pStateM;
    public:
        State();
        virtual ~State();
        void setStateMachine(StateMachine* pSM);
        void changeState(std::string stateName);
        virtual void update(float dt) = 0;
        virtual void handleEvents() = 0;
        virtual void render() = 0;
    };

}