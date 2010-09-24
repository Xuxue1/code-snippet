#ifndef _CSLOCK_H_
#define _CSLOCK_H_
#include <Windows.h>
class CSLock
{
public:
    CSLock(CRITICAL_SECTION &cs)
    {
        CritSect = &cs;
        EnterCriticalSection(CritSect);
        IsLocked = true;
    }

    ~CSLock()
    {
        if (!IsLocked) return;
        IsLocked = false;
        LeaveCriticalSection(CritSect);
    }

    void Unlock()
    {
        IsLocked = false;
        LeaveCriticalSection(CritSect);
    }

    void Relock()
    {
        EnterCriticalSection(CritSect);
        IsLocked = true;
    }

    static bool Init(CRITICAL_SECTION &cs)
    {
        return (InitializeCriticalSectionAndSpinCount(&cs, 4000) == TRUE);
    }

    static void Destroy(CRITICAL_SECTION &cs)
    {
        DeleteCriticalSection(&cs);
    }

private:
    CRITICAL_SECTION *CritSect;
    bool IsLocked;

private:
    CSLock();
};

#endif