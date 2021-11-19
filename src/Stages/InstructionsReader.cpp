#include "Stages/InstructionsReader.h"
using namespace Stages;

InstructionsReader::InstructionsReader(): commands() {

}

InstructionsReader::~InstructionsReader() {
    commands.clear();
}

void InstructionsReader::convertStringToVector(std::string s) {
    std::string space_delimiter = " ";
    size_t pos = 0;
    while ((pos = s.find(space_delimiter)) != std::string::npos) {
        commands.push_back(s.substr(0, pos));
        s.erase(0, pos + space_delimiter.length());
    }
}

void InstructionsReader::readInstructions(std::string instructionsPath) {
    std::ifstream file(instructionsPath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            convertStringToVector(line);
            executeInstructions();
            commands.clear();
        }
        file.close();
    }
}