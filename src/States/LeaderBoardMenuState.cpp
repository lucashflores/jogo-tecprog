#include "States/GameStateMachine.h"
using namespace States;

LeaderBoardMenuState::LeaderBoardMenuState(GameStateMachine *pGM): Menus::LeaderBoardMenu() {
    if (pGM)
        pGameStateMachine = pGM;

}

LeaderBoardMenuState::~LeaderBoardMenuState() {
    pGameStateMachine = NULL;
}

void LeaderBoardMenuState::update(float dt) {
    updateButtons();
    render();
}

void LeaderBoardMenuState::render() {
    //renderItems();
    renderLines();
    renderTitle();
}

void LeaderBoardMenuState::reset() {
    buttonSelected = 0;
    pGameStateMachine->clearKeyPressedInFrame();
    resetMapAndVectors();
    updateButtons();
    loadLeaderBoard();
    createLeaderBoard();
    render();
}

void LeaderBoardMenuState::exec() {
    if (buttonSelected == 0)
        changeState("ExitState");
    else
        return;
}

void LeaderBoardMenuState::select() {
    exec();
}

void LeaderBoardMenuState::back() {
    changeState("MainMenuState");
}

std::vector<std::string> LeaderBoardMenuState::convertStringToVector(std::string s, std::vector<std::string> commands) {
    std::string temp = "";
    for(int i=0;i<s.length();++i){

        if(s[i]==' '){
            commands.push_back(temp);
            temp = "";
        }
        else{
            temp.push_back(s[i]);
        }

    }
    commands.push_back(temp);
    return commands;
}

void LeaderBoardMenuState::loadLeaderBoard() {
    std::ifstream leaderBoardSave(LEADERBOARD_SAVE);


    std::vector<std::string> commands;

    std::string name;
    std::string line;
    while (std::getline(leaderBoardSave, line)) {
        commands = convertStringToVector(line, commands);
        if (commands.size() > 1)
            insertInLeaderBoard((unsigned int) (std::stoi(commands[0])), commands[1]);
        commands.clear();
    }
    commands.clear();
    leaderBoardSave.close();
}

