#include <assert.h>
#include "Mutex.h"
#include "Utils.h"
CMutex::CMutex()
{
    HANDLE hMutex = NULL;

    assert(sizeof(hMutex) == sizeof(mState));

    hMutex = CreateMutex(NULL, FALSE, NULL);
    mState = (void *)hMutex;
}

CMutex::CMutex(const char* name)
{

    HANDLE hMutex;

    assert(sizeof(hMutex) == sizeof(mState));

    hMutex = CreateMutex(NULL, FALSE, name);
    mState = (void *)hMutex;
}

CMutex::CMutex(int type, const char* name)
{
    // XXX: type  not used for now
    HANDLE hMutex;

    assert(sizeof(hMutex) == sizeof(mState));

    hMutex = CreateMutex(NULL, FALSE, name);
    mState = (void *)hMutex;
}

CMutex::~CMutex()
{
    CloseHandle((HANDLE)mState);
}

int CMutex::lock()
{
    DWORD dwWaitResult;
    dwWaitResult = WaitForSingleObject((HANDLE) mState, INFINITE);
    return dwWaitResult != WAIT_OBJECT_0 ? -1 : NO_ERROR;
}

void CMutex::unlock()
{
    if (!ReleaseMutex((HANDLE) mState))
    {
        DbgPrintf("Can not unlock!");
    }
}

int CMutex::tryLock()
{
    DWORD dwWaitResult;
    dwWaitResult = WaitForSingleObject((HANDLE)mState, 0);
    if (dwWaitResult != WAIT_OBJECT_0 && dwWaitResult != WAIT_TIMEOUT)
    {
        DbgPrintf("Can not lock!");
    }
    return (dwWaitResult == WAIT_OBJECT_0) ? 0 : -1;
}