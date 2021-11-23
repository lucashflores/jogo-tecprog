#include "Stages/InstructionsReader.h"
using namespace Stages;

InstructionsReader::InstructionsReader(): commands() {

}

InstructionsReader::~InstructionsReader() {
    commands.clear();
}

void InstructionsReader::convertStringToVector(std::string s) {
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
}

void InstructionsReader::readInstructions(std::string instructionsPath) {
    std::ifstream file(instructionsPath);
    std::string line;
    while (std::getline(file, line)) {
        convertStringToVector(line);
        executeInstructions();
        commands.clear();
    }
    file.close();
}