#pragma once
#include "StateMachine.h"
#include "Managers/GraphicManager.h"
#include "Managers/EventManager.h"
#include "Managers/InputManager.h"
#include "States/MainMenuState.h"
#include "States/ExitState.h"
#include "Stages/StageLoader.h"
#include "States/NewGameMenuState.h"
#include "States/CreatingStage1State.h"
#include "States/PlayingState.h"
#include "States/NewStage2MenuState.h"
#include "States/CreatingStage2State.h"
#include "States/LoadGameState.h"
#include "States/PauseMenuState.h"
#include "States/SaveGameState.h"
#include "States/EndGameMenuState.h"
#include "States/LeaderBoardMenuState.h"
#include "States/SavingLeaderBoardState.h"

namespace States {

    class GameStateMachine: public StateMachine {
    private:
        Managers::GraphicManager* pGraphicM;
        Managers::EventManager* pEventM;
        Managers::InputManager* pInputM;
        Stages::Stage* pStage;
        Entities::Player* player1;
        Entities::Player* player2;
        std::string name;
        unsigned int score;
        bool twoPlayers;
        int currentStage;
        sf::Clock time;

    public:
        GameStateMachine();
        ~GameStateMachine();
        void initializeStates();

        void exec();

        Stages::Stage* getStage() const;
        void setStage(Stages::Stage* pS);

        void setTwoPlayers(bool tp);
        bool getTwoPlayers() const;

        void setName(std::string n);
        std::string getName();


        Entities::Player* getPLayer1();
        Entities::Player* getPLayer2();
        bool isTwoPlayersActive() const;

        unsigned int getScore();
        void setScore(unsigned int scr);

        int getCurrentStage() const;
        void setCurrentStage(int num);

        void setGameViewSize(Coordinates::Vector<float> size);
        void centerGameView(Coordinates::Vector<float> pos);

        void loadGame();
        void endGame();
        void deleteStage();
        void resetPlayers();

        void clearKeyPressedInFrame();
    };

}