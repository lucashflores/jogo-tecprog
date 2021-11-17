#include "Stages/InstructionsTranslator.h"
using namespace Stages;

InstructionsTranslator::InstructionsTranslator(StageBuilder* pSG) {
    pStageBuilder = NULL;
    if (pSG)
        pStageBuilder = pSG;
}

InstructionsTranslator::~InstructionsTranslator() { pStageBuilder = NULL; }

void InstructionsTranslator::convertString(std::string s) {
    std::string space_delimiter = " ";
    size_t pos = 0;
    while ((pos = s.find(space_delimiter)) != std::string::npos) {
        commands.push_back(s.substr(0, pos));
        s.erase(0, pos + space_delimiter.length());
    }
}

void InstructionsTranslator::translateInstructions(std::string instructionsPath) {
    std::ifstream file(instructionsPath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            convertString(line);
            builderCommands();
            commands.clear();
        }
        file.close();
    }
}

void InstructionsTranslator::builderCommands() {
    std::string command = commands[0];
    if (command == "T")
        tileMakerCommands();
    else if (command == "O")
        objectBuilderCommands();
    else if (command == "E")
        enemySpawnerCommands();
    else
        exit(1);
}

void InstructionsTranslator::tileMakerCommands() {
    std::string command = commands[1];
    float positionX = std::stof(commands[2]);
    float positionY = std::stof(commands[3]);
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    if (command == "G" || command == "R" || command == "W") {
        int size = std::stoi(commands[4]);
        if (command == "G")
            pStageBuilder->makePlatform(position, size);
        else if (command == "R")
            pStageBuilder->makeRoof(position, size);
        else if (command == "W") {
            bool right = false;
            if (std::stoi(commands[5]))
                right = true;
            pStageBuilder->makeWall(position, size, right);
        }
    }
    else if (command == "B") {
        float sizeX = std::stod(commands[4]);
        float sizeY = std::stod(commands[5]);
        Coordinates::Vector<unsigned int> size = Coordinates::Vector<unsigned int>(sizeX, sizeY);
        pStageBuilder->makeTileBackground(position, size);
    }

}

void InstructionsTranslator::objectBuilderCommands() {
    std::string command = commands[1];
    float positionX = std::stof(commands[2]);
    float positionY = std::stof(commands[3]);
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    if (command == "B")
        pStageBuilder->buildBarrel(position);
    else if (command == "F")
        pStageBuilder->buildFire(position);
    else if (command == "S")
        pStageBuilder->buildSign(position);
    else if (command == "O")
        pStageBuilder->buildOilTile(position);
    else
        exit(1);

}

void InstructionsTranslator::enemySpawnerCommands() {
    std::string command = commands[1];
    float positionX = std::stof(commands[2]);
    float positionY = std::stof(commands[3]);
    Coordinates::Vector<float> position = Coordinates::Vector<float>(positionX, positionY);
    if (command == "S")
        pStageBuilder->spawnSmokerEnemy(position);
    /*
    else if (command == "D")
        pStageBuilder->spawnDogEnemy(position);
    else if (command == "B")
        pStageBuilder->spawnBoss(position);
    */
    else
        exit(1);
}
