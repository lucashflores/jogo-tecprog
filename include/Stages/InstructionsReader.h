#pragma once

#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

namespace Stages {

    class InstructionsReader {
    protected:
        std::vector<std::string> commands;

    public:
        InstructionsReader();
        ~InstructionsReader();
        void convertStringToVector(std::string s);
        void readInstructions(std::string instructionsPath);
        virtual void executeInstructions() = 0;
    };
}