/*
Author of code: Prof. Dr. Jean M. Simão.
With permission for use in the project development.
*/
#pragma once

#include <iostream>
#include <string>
#include <pthread.h>

namespace Concurrent {

    // Infrastructure Class
    class Thread {

    private:

        pthread_t _threadID;
        static pthread_mutex_t _mutex;
        pthread_attr_t _tAttribute;

    private:

        static void* runThread(void* _pThread);
        virtual void run()=0;
        void printError(const std::string msg) const;

    public:

        Thread();
        virtual ~Thread();

        // Makes runThread runs in a Thread
        void start();

        // Allows the master thread to wait to the ramified thread
        void join();

        // Free the processor
        void yield();

        static void lock();

        static void unlock();

        static void trylock();
    };
}
