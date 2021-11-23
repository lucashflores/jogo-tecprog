#include "States/State.h"
#include "States/GameStateMachine.h"
#include "Stages/StageFactory.h"
#include "Stages/Stage1Factory.h"
#include "Stages/Stage2Factory.h"


namespace States {
    class NewGameState: State {
    private:
        GameStateMachine* game;
    public:
        NewGameState(GameStateMachine* gm = NULL);

        ~NewGameState();

        void update(float dt);

        void exec();

        void render();

        void startNewStage(int stg, bool twoPlayers);
    };
}