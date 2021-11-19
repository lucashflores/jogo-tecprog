#include "Entities/Player.h"



namespace  Entities {
    class Player;
}

class PlayerControl {
private:
    Managers::InputManager* pInputManager;
    std::map<std::string, std::string> controls;
    Entities::Player* player;
public:
    PlayerControl(Entities::Player* p);
    ~PlayerControl();
    void notify();
};