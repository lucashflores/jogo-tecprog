#include "Managers/EventManager.h"
using namespace Managers;

EventManager* EventManager::instance = NULL;

EventManager *EventManager::getInstance() {
    if (instance == NULL)
        instance = new EventManager();
    return instance;
}

EventManager::EventManager() {
    pGraphicManager = Managers::GraphicManager::getInstance();
    pInputManager = Managers::InputManager::getInstance();
    window = pGraphicManager->getWindow();
}

EventManager::~EventManager() {

}

void EventManager::pollEvents(sf::Event event) {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            pGraphicManager->closeWindow();
        if (event.type == sf::Event::KeyPressed)
            pInputManager->handleKeyPressed(event.key.code);
        if (event.type == sf::Event::KeyReleased)
            pInputManager->handleKeyReleased(event.key.code);
    }
}

