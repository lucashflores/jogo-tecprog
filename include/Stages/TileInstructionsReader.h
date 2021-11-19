#pragma once
#include "TileFactory.h"
#include "InstructionsReader.h"

namespace Stages {

    class TileInstructionsReader: public InstructionsReader {
    private:
        TileFactory* pTileFactory;
    public:
        TileInstructionsReader(TileFactory* pTF);
        ~TileInstructionsReader();
        void executeInstructions();
    };

}