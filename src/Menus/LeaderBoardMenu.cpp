#include "Menus/LeaderBoardMenu.h"
using namespace Menus;

LeaderBoardMenu::LeaderBoardMenu(): Menu(), leaderBoard(), rankLines(), nameLines(), scoreLines() {
    menuTitle =  new Text(Coordinates::Vector<float>(640.f, 50.f), "LEADERBOARD");
    menuTitle->setSize(60);
    menuTitle->centralize();

    rankTitle = new Text(Coordinates::Vector<float>(384.f, 150.f), "RANK");
    rankTitle->setSize(40);
    rankTitle->centralize();

    nameTitle = new Text(Coordinates::Vector<float>(640.f, 150.f), "NAME");
    nameTitle->setSize(40);
    nameTitle->centralize();

    scoreTitle = new Text(Coordinates::Vector<float>(896.f, 150.f), "SCORE");
    scoreTitle->setSize(40);
    scoreTitle->centralize();

}

LeaderBoardMenu::~LeaderBoardMenu() {
    leaderBoard.clear();
    for (int i = 0; i < rankLines.size(); i++) {
        if (rankLines[i])
            delete rankLines[i];
    }
    rankLines.clear();

    for (int i = 0; i < nameLines.size(); i++) {
        if (nameLines[i])
            delete nameLines[i];
    }
    nameLines.clear();

    for (int i = 0; i < scoreLines.size(); i++) {
        if (scoreLines[i])
            delete scoreLines[i];
    }
    scoreLines.clear();
}

void LeaderBoardMenu::createButtons() {
    Menus::Button* b = NULL;
    b = new Menus::Button(Coordinates::Vector<float>(640.f, 650.f), "Exit");
    buttons.push_back(b);
    b = NULL;
}

void LeaderBoardMenu::createLeaderBoard() {
    int index = 1;
    for( auto it = leaderBoard.begin(); it != leaderBoard.end() && index < 11; it++) {// = leaderBoard.upper_bound(it->first)) {
        createLeaderBoardLine(index, it->second, it->first);
        index++;
    }
}

void LeaderBoardMenu::createLeaderBoardLine(int index, std::string name, unsigned int score) {

    float positionY = 150.f + ((rankLines.size() + 1) * 50.f);

    Text* rankLine = NULL;
    Text* nameLine = NULL;
    Text* scoreLine = NULL;

    std::string i = std::to_string(index);
    std::string rank;
    if (index == 1)
        rank = i + "ST";
    else if (index == 2)
        rank = i + "ND";
    else if (index == 3)
        rank = i + "RD";
    else
        rank = i + "TH";
    rankLine = new Text(Coordinates::Vector<float>(384.f, positionY), rank);
    rankLine->centralize();
    rankLines.push_back(rankLine);

    nameLine = new Text(Coordinates::Vector<float>(640.f, positionY), name);
    nameLine->centralize();
    nameLines.push_back(nameLine);

    std::string scr = std::to_string(score);
    scoreLine = new Text(Coordinates::Vector<float>(896.f, positionY), scr);
    scoreLine->centralize();
    scoreLines.push_back(scoreLine);

}

void LeaderBoardMenu::insertInLeaderBoard(unsigned int score, std::string name) {
    leaderBoard.insert(std::pair<unsigned int, std::string>(score, name));
}


void LeaderBoardMenu::renderRankLines() {
    for (int i = 0; i < rankLines.size(); i++) {
        rankLines[i]->render();
    }
}

void LeaderBoardMenu::renderNameLines() {
    for (int i = 0; i < nameLines.size(); i++) {
        nameLines[i]->render();
    }
}

void LeaderBoardMenu::renderScoreLines() {
    for (int i = 0; i < scoreLines.size(); i++) {
        scoreLines[i]->render();
    }
}

void LeaderBoardMenu::renderLines() {
    renderRankLines();
    renderNameLines();
    renderScoreLines();
}

void LeaderBoardMenu::renderTitle() {
    rankTitle->render();
    scoreTitle->render();
    nameTitle->render();
    menuTitle->render();
}

void LeaderBoardMenu::resetMapAndVectors() {
    leaderBoard.clear();

    for (int i = 0; i < rankLines.size(); i++) {
        if (rankLines[i])
            delete rankLines[i];
    }
    rankLines.clear();

    for (int i = 0; i < nameLines.size(); i++) {
        if (nameLines[i])
            delete nameLines[i];
    }
    nameLines.clear();

    for (int i = 0; i < scoreLines.size(); i++) {
        if (scoreLines[i])
            delete scoreLines[i];
    }
    scoreLines.clear();

}


