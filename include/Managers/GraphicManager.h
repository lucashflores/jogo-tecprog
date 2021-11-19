#pragma once

#include "IManager.h"
#include <string.h>

namespace Managers {

    class GraphicManager {
    private:
        sf::RenderWindow *window;
        sf::View view;

        static GraphicManager *instance;

        GraphicManager();

    public:
        ~GraphicManager();

        static GraphicManager *getInstance();

        sf::RenderWindow *getWindow();

        void render(sf::RectangleShape *body);

        void display();

        void clear();

        bool isWindowOpen() const;

        void closeWindow();

        void centerView(Coordinates::Vector<float> pos);

        sf::Texture* loadTexture(std::string path);
    };

}




