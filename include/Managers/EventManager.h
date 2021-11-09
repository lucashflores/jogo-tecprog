#pragma once

#include "stdafx.h"
#include "Managers/GraphicManager.h"
#include "Managers/InputManager.h"

namespace Managers {

    class EventManager {
    private:
        GraphicManager *pGraphicManager;
        sf::RenderWindow *window;
        InputManager *pInputManager;

        static EventManager *instance;

        EventManager();

    public:
        ~EventManager();

        static EventManager *getInstance();


        void PollEvents(sf::Event event);
    };

}