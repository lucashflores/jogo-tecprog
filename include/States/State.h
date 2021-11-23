#pragma once

#include "StateMachine.h"
#include "State.h"
#include "Stages/Stage.h"
#include "Entities/Player.h"


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

        virtual void render() = 0;

        virtual void reset() = 0;

        virtual void exec() = 0;
    };

}