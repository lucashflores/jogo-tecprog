#include "Concurrent/Thread.h"
using namespace Concurrent;

pthread_mutex_t Thread::_mutex = PTHREAD_MUTEX_INITIALIZER;

Thread::Thread() {

}

Thread::~Thread() {
    if ( NULL != Thread::_mutex )
        pthread_mutex_destroy( &Thread::_mutex );
}

void Thread::run() {

}

//Starts the Thread, sets attributes to Thread and creates the Thread.
void Thread::start() {

    int status = 0;
    //initiate the attribute
    status = pthread_attr_init(&_tAttribute);
        //A thread vai ser enxergada apenas pelo âmbito do programa
    status = pthread_attr_setscope(&_tAttribute, PTHREAD_SCOPE_SYSTEM);

    if(status!=0)
        printError("Fail to initialize Thread attribute");

    //creates a thread
    status = pthread_create(&_threadID, &_tAttribute, Thread::runThread, (void*)this);
    if(status!=0)
        printError("Fail to initialize Thread");

    //destroys the atttribute
    status = pthread_attr_destroy(&_tAttribute);
    if(status!=0)
        printError("Fail to destroy Thread attribute");
}

void Thread::join() {
    if (pthread_join(_threadID, NULL))
        printError("on Thread::join() - Could not join thread");
}

void Thread::yield() {
    sched_yield();
}

// Run the Thread - Executes the run method defined by child class.
void* Thread::runThread(void* _pThread) {

    Thread* pThread = static_cast<Thread*>(_pThread);

    if (pThread == NULL)
        std::cout << "ERROR: on Thread::runThread(void* _pThread) - NULL pointer to Thread" << std::endl;
    else
        pThread->run();

    return NULL;

}

// Print Error Message
void Thread::printError(const std::string msg) const {
    std::cout << "ERROR: " << msg << std::endl;
}

void Thread::lock() {
    if ( Thread::_mutex == NULL )
        pthread_mutex_init( &Thread::_mutex, NULL );

    pthread_mutex_lock( &Thread::_mutex );
}

void Thread::unlock() {
    if ( NULL != Thread::_mutex )
        pthread_mutex_unlock( &Thread::_mutex );
}

void Thread::trylock() {
    if ( NULL != Thread::_mutex )
        pthread_mutex_trylock( &Thread::_mutex );
}