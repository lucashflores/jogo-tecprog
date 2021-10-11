#include "EventManager.h"

EventManager* EventManager::instance = NULL;

EventManager *EventManager::getInstance() {
    if (instance == NULL)
        instance = new EventManager();
    return instance;
}

EventManager::EventManager() {

}

EventManager::~EventManager() {

}

void EventManager::setGraphicManagerInstance(GraphicManager *instance) {
    pGraphicManager = instance;
    setWindow(pGraphicManager->getWindow());
}

void EventManager::setWindow(sf::RenderWindow *pWindow) {
    window = pWindow;
}

void EventManager::setInputManagerInstance(InputManager *instance) {
    pInputManager = instance;
}

void EventManager::PollEvents(sf::Event event) {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            pGraphicManager->closeWindow();
        if (event.type == sf::Event::KeyPressed)
            pInputManager->handleKeyPressed(event.key.code);
        if (event.type == sf::Event::KeyReleased)
            pInputManager->handleKeyReleased(event.key.code);

    }
}

