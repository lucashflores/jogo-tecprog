#include "States/GameStateMachine.h"
#include "Concurrent/BossThread.h"


int main() {

    //Concurrent::BossThread*


    srand(time(NULL));
    States::GameStateMachine* game = new States::GameStateMachine();
    game->exec();
    delete game;
    return 0;
}
