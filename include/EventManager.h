#pragma once

#include "stdafx.h"
#include "GraphicManager.h"
#include "InputManager.h"

class EventManager {
private:
    GraphicManager* pGraphicManager;
    sf::RenderWindow* window;
    InputManager* pInputManager;

    static EventManager* instance;
    EventManager();
public:
    ~EventManager();
    static EventManager* getInstance();
    void setGraphicManagerInstance(GraphicManager* instance);
    void setInputManagerInstance(InputManager* instance);
    void setWindow(sf::RenderWindow* pWindow);
    void PollEvents(sf::Event event);
};