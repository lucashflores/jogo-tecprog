#pragma once

#include "StageBuilder.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

namespace Stages {
    class InstructionsTranslator {
    private:
        StageBuilder* pStageBuilder;
        std::vector<std::string> commands;
    public:
        InstructionsTranslator(StageBuilder* pSG);
        ~InstructionsTranslator();
        void convertString(std::string s);
        void translateInstructions(std::string instructionsPath);
        void builderCommands();
        void tileMakerCommands();
        void objectBuilderCommands();
        void enemySpawnerCommands();
    };
}