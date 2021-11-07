#include "Entities/Player.h"

#define VELOCITY_X 0.2f
#define VELOCITY_Y 0.0f
class PlayerControl {
private:
    Managers::InputManager *pInputManager;
    std::map<std::string, sf::Keyboard::Key> controls;
public:
    PlayerControl(bool isPlayerOne);
    ~PlayerControl();
    const bool isPlayerWalking();
    const bool isPlayerFacingLeft();
    void movePlayer(Entities::Player* player);
};