#pragma once
#include "Concurrent/Thread.h"
#include "Entities/PunkBoss.h"

namespace Concurrent {

    class BossThread: public Thread, public Entities::PunkBoss{

    private:

        bool _canRun;
        bool _isAlive;
        static const float *pDt;//aponta para contador de tempo da main thread
        static float last_pDt;

    private:

        void run();

    public:

        BossThread(Coordinates::Vector<float> pos);
        ~BossThread();

        void stop();
        void pause(const bool pause);//true para pausar e false para despausar thread

        const bool isAlive() const;

        static void set_pDt(const float &dt);

        Entities::PunkBoss* getPunkBoss();

    };

}