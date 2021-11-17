#pragma once

#include <ifstream>

namespace Stages {
    class InstructionsTranslator {
    public:
        InstructionsTranslator();
        ~InstructionsTranslator();
        void translateAllInstructions(std::string instructionsPath);
    };
}