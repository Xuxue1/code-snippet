#ifndef _RL_MUTEX_
#define _RL_MUTEX_
#include <Windows.h>
class CMutex 
{
public:
    CMutex();
    CMutex(const char* name);
    CMutex(int type, const char* name = NULL);
    ~CMutex();

    // lock or unlock the mutex
    int    lock();
    void   unlock();

    // lock if possible; returns 0 on success, error otherwise
    int    tryLock();

    // Manages the mutex automatically. It'll be locked when Autolock is
    // constructed and released when Autolock goes out of scope.
    class Autolock {
    public:
        inline Autolock(CMutex& mutex) : mLock(mutex)  { mLock.lock(); }
        inline Autolock(CMutex* mutex) : mLock(*mutex) { mLock.lock(); }
        inline ~Autolock() { mLock.unlock(); }
    private:
        CMutex& mLock;
    };
private:
    // A mutex cannot be copied
    CMutex(const CMutex&);
    CMutex& operator = (const CMutex&);
    void*   mState;
};

#endif