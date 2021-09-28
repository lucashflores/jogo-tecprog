#pragma once

#include <SFML/Graphics.hpp>

class GraphicManager {
private:
    sf::RenderWindow* window;
    sf::View view;

    static GraphicManager* instance;
    GraphicManager();

public:
    ~GraphicManager();

    static GraphicManager* getInstance();
    sf::RenderWindow* getWindow();
    void render(sf::RectangleShape* body);
    void display();
    void clear();
    bool isWindowOpen() const;
    void closeWindow();
    void centerView(sf::Vector2f pos);
    sf::Texture* loadTexture(const char* path);
};



