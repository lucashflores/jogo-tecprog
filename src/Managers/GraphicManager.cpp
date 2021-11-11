#include "Managers/GraphicManager.h"
using namespace Managers;

GraphicManager* GraphicManager::instance = NULL;

GraphicManager* GraphicManager::getInstance() {
    if (instance == NULL) {
        instance = new GraphicManager();
    }
    return instance;
}

GraphicManager::GraphicManager() {
    window = new sf::RenderWindow;
    window->create(sf::VideoMode(1280, 720), "TecPunk 2021");
    view.setCenter(sf::Vector2f(320.f, 240.f));
    view.setSize(sf::Vector2f(640.f, 480.f));
}

GraphicManager::~GraphicManager() {
    delete(window);
}

sf::RenderWindow* GraphicManager::getWindow() {
    return instance->window;
}

void GraphicManager:: render(sf::RectangleShape* body) {
    window->draw(*body);
}

void GraphicManager::display() {
    window->display();
}

void GraphicManager::clear() {
    window->clear();
}

bool GraphicManager::isWindowOpen() const {
    return window->isOpen();
}

void GraphicManager::closeWindow() {
    window->close();
}

void GraphicManager::centerView(sf::Vector2f pos) {
    view.setCenter(pos);
    window->setView(view);
}

sf::Texture* GraphicManager::loadTexture(std::string path) {
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(path);
    return texture;
}
