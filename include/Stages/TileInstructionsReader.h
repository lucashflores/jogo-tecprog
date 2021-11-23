#pragma once
#include "TileMaker.h"
#include "InstructionsReader.h"

namespace Stages {

    class TileInstructionsReader: public InstructionsReader {
    private:
        TileMaker* pTileMaker;
    public:
        TileInstructionsReader(int stg, EntityList* pEL);
        ~TileInstructionsReader();
        void executeInstructions();
    };

}