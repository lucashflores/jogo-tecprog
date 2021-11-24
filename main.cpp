#include "States/GameStateMachine.h"


int main() {
    srand(time(NULL));
    States::GameStateMachine* game = new States::GameStateMachine();
    game->exec();
    return 0;
}
