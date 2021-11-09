#include "Entities/Player.h"

#define PLAYER1_LEFT "A"
#define PLAYER1_RIGHT "D"
#define PLAYER1_JUMP "W"
#define PLAYER1_ATTACK "Space"

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