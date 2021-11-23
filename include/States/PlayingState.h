#pragma once
#include "State.h"


namespace States {
    class PlayingState: public State {
    private:
        Stages::Stage* pStage;
    public:
        PlayingState(Stages::Stage* pS);
        ~PlayingState();
        void setStage(Stages::Stage* pS);
        Stages::Stage* getStage();
        void exec(float dt);
    };
}