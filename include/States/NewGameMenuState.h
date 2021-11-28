#include "States/State.h"
#include "Stages/StageFactory.h"
#include "Stages/Stage1Factory.h"
#include "Menus/NewStageMenu.h"


namespace States {

    class GameStateMachine;

    class NewGameMenuState: public State, public Menus::NewStageMenu {
    private:
        GameStateMachine* pGameStateMachine;
    public:
        NewGameMenuState(GameStateMachine* pGM);
        ~NewGameMenuState();
        void createButtons();
        void update(float dt);
        void render();
        void reset();
        void exec();
        void select();
        void back();
    };
}