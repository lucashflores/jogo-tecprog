#pragma once
#include "StateMachine.h"
#include "Managers/GraphicManager.h"
#include "Managers/EventManager.h"
#include "Managers/InputManager.h"

namespace States {

    class GameStateMachine: public StateMachine {
    private:
        Managers::GraphicManager* pGraphicM;
        Managers::EventManager* pEventM;
        Managers::InputManager* pInputM;
    public:
        GameStateMachine();
        ~GameStateMachine();
        void setGraphicManager(Managers::GraphicManager* pGM);
        void setEventManager(Managers::EventManager* pEM);
        void setInputManager(Managers::InputManager* pIM);
        Managers::GraphicManager* getGraphicManager();
        Managers::EventManager* getEventManager();
        Managers::InputManager* getInputManager();
    };

}