#pragma once
#include "StateMachine.h"
#include "Managers/GraphicManager.h"
#include "Managers/EventManager.h"
#include "Managers/InputManager.h"
#include "States/MainMenuState.h"
#include "States/ExitState.h"
#include "Stages/StageLoader.h"

namespace States {

    class GameStateMachine: public StateMachine {
    private:
        Managers::GraphicManager* pGraphicM;
        Managers::EventManager* pEventM;
        Managers::InputManager* pInputM;
        Stages::Stage* pStage;
        Entities::Player* player1;
        Entities::Player* player2;
        int currentStage;
        sf::Clock time;

    public:
        GameStateMachine();
        ~GameStateMachine();
        void initializeStates();

        void exec();
        void save();

        Stages::Stage* getStage() const;
        void setStage(Stages::Stage* pS);

        Entities::Player* getPLayer1();
        Entities::Player* getPLayer2();
        bool isTwoPlayersActive() const;

        int getCurrentStage() const;
        void setCurrentStage(int num);

        void loadGame();
        void endGame();
        void deleteStage();
        void resetPlayers();
    };

}