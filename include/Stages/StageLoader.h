#include "Stage1Factory.h"
#include "Stage2Factory.h"
#include "ProjectileMaker.h"

namespace Stages {

    class StageLoader {
    private:
        std::vector<std::string> commands;
        TileInstructionsReader* tileInstructionsReader;
        EnemyMaker* enemyMaker;
        ObstacleMaker* obstacleMaker;
        ProjectileMaker* projectileMaker;

    public:
        StageLoader();
        ~StageLoader();

        void convertStringToVector(std::string s);

        void loadPlayer1(Entities::Player* player1);
        void loadPlayer2(Entities::Player* player2);

        Stage* loadStage(Entities::Player* player1, Entities::Player* player2);
        Stage1* loadStage1(EntityList* pEL, Entities::Player* player1, Entities::Player* player2);
        Stage2* loadStage2(EntityList* pEL, Entities::Player* player1, Entities::Player* player2);

        void loadObstacles(EntityList* pEL);
        void loadEnemies(EntityList* pEL, Entities::Player* player1, Entities::Player* player2);
        void loadProjectiles(EntityList* pEL);

        void makeObstacles(EntityList* pEL);
        void makeEnemies(EntityList *pEL, Entities::Player* player1, Entities::Player* player2);
        void makeProjectiles(EntityList* pEL);
    };
}