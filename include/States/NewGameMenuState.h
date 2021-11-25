#include "States/State.h"
#include "Stages/StageFactory.h"
#include "Stages/Stage1Factory.h"
#include "Menus/Menu.h"


namespace States {

    class GameStateMachine;

    class NewGameMenuState: public State, public Menus::Menu {
    private:
        GameStateMachine* pGameStateMachine;
        Managers::InputManager* pInputManager;
    public:
        NewGameMenuState(GameStateMachine* pGM);

        ~NewGameMenuState();

        void createButtons();
        void update(float dt);
        void render();
        void reset();
        void exec();
        void select();

    };
}