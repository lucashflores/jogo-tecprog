#include "State.h"

namespace States {
    class GameStateMachine;

    class ExitState: public State {
    private:
        GameStateMachine* pGameStateMachine;
    public:
        ExitState(GameStateMachine* pGM);
        ~ExitState();
        void update(float dt);
        void render();
        void reset();
        void exec();
    };
}
