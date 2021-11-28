#pragma once


#include "Menu.h"
#include "Text.h"
#include <map>
#include <vector>

namespace Menus {
    class LeaderBoardMenu: public Menu {
    private:
        std::multimap<unsigned int, std::string, std::greater<unsigned int>> leaderBoard;
        Text* rankTitle;
        Text* nameTitle;
        Text* scoreTitle;
        std::vector<Text*> rankLines;
        std::vector<Text*> nameLines;
        std::vector<Text*> scoreLines;
    public:
        LeaderBoardMenu();
        ~LeaderBoardMenu();
        void createLeaderBoardLine(int index, std::string name, unsigned int score);
        void createLeaderBoard();
        void createButtons();
        void insertInLeaderBoard(unsigned int score, std::string name);
        void renderRankLines();
        void renderNameLines();
        void renderScoreLines();
        void renderLines();
        void renderTitle();
        void resetMapAndVectors();
        void select() = 0;
        void back() = 0;
    };
}