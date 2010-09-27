/* Queue functions */
#include "Queue.h"


/* Finite bounded queue management functions */
/* Note the placeholders for MaxWait and TimedOut
 * They are not used in this solution; alternative solutions
 * could implement a timeout feature
 */

DWORD q_get(queue_t *q, PVOID msg, DWORD msize, DWORD MaxWait)
{
    DWORD TotalWaitTime = 0;
    BOOL TimedOut = FALSE;

    if (q_destroyed(q)) return 1;
    WaitForSingleObject (q->q_guard, INFINITE);
    while (q_empty (q) && !TimedOut) {
        SignalObjectAndWait (q->q_guard, q->q_ne, INFINITE, FALSE);
        WaitForSingleObject (q->q_guard, INFINITE);
    }
    /* remove the message from the queue */
    if (!TimedOut) q_remove (q, msg, msize);
    /* Signal that the queue is not full as we've removed a message */
    PulseEvent (q->q_nf);
    ReleaseMutex (q->q_guard);

    return TimedOut ? WAIT_TIMEOUT : 0;
}

DWORD q_put(queue_t *q, PVOID msg, DWORD msize, DWORD MaxWait)
{
    DWORD TotalWaitTime = 0;
    BOOL TimedOut = FALSE;

    if (q_destroyed(q)) return 1;
    WaitForSingleObject (q->q_guard, INFINITE);
    while (q_full (q) && !TimedOut) {
        SignalObjectAndWait (q->q_guard, q->q_nf, INFINITE, FALSE);
        WaitForSingleObject (q->q_guard, INFINITE);
    }
    /* Put the message in the queue */
    if (!TimedOut) q_insert (q, msg, msize);    
    /* Signal that the queue is not empty as we've inserted a message */
    PulseEvent (q->q_ne);
    ReleaseMutex (q->q_guard);
 
    return TimedOut ? WAIT_TIMEOUT : 0;
}

DWORD q_initialize(queue_t *q, DWORD msize, DWORD nmsgs)
{
    /* Initialize queue, including its mutex and events */
    /* Allocate storage for all messages. */
    
    q->q_first = q->q_last = 0;
    q->q_size = nmsgs;
    q->q_destroyed = 0;

    q->q_guard = CreateMutex(NULL, FALSE, NULL);
    q->q_ne = CreateEvent(NULL, TRUE, FALSE, NULL);
    q->q_nf = CreateEvent(NULL, TRUE, FALSE, NULL);

    if ((q->msg_array = calloc (nmsgs, msize)) == NULL) return 1;
    return 0; /* No error */
}

DWORD q_destroy(queue_t *q)
{
    if (q_destroyed(q)) return 1;
    /* Free all the resources created by q_initialize */
    WaitForSingleObject (q->q_guard, INFINITE);
    q->q_destroyed = 1;
    free (q->msg_array);
    CloseHandle(q->q_ne);
    CloseHandle(q->q_nf);
    ReleaseMutex(q->q_guard);
    CloseHandle(q->q_guard);

    return 0;
}

DWORD q_destroyed(queue_t *q)
{
    return (q->q_destroyed);
}

DWORD q_empty(queue_t *q)
{
    return (q->q_first == q->q_last);
}

DWORD q_full(queue_t *q)
{
//  return ((q->q_last - q->q_first) == 1 || 
//      (q->q_first == q->q_size-1 && q->q_last == 0));
// JH Note (Aug 14, 2005). The error (commented out above)
//    has been in this code for several years and, remarkably,
//    has eluded detetction, even though a number of people have
//    looked at this code.
    return ((q->q_first - q->q_last) == 1 ||
            (q->q_last == q->q_size-1 && q->q_first == 0));
}


DWORD q_remove(queue_t *q, PVOID msg, DWORD msize)
{
    char *pm;

    if (q_empty(q)) return 1; /* Error - Q is empty */
    pm = (char *)q->msg_array;
    /* Remove oldest ("first") message */
    memcpy (msg, pm + (q->q_first * msize), msize);
    q->q_first = ((q->q_first + 1) % q->q_size);
    return 0; /* no error */
}

DWORD q_insert(queue_t *q, PVOID msg, DWORD msize)
{
    char *pm;

    if (q_full(q)) return 1; /* Error - Q is full */
    pm = (char *)q->msg_array;
    /* Add a new youngest ("last") message */
    memcpy (pm + (q->q_last * msize), msg, msize);
    q->q_last = ((q->q_last + 1) % q->q_size);
    return 0;
}
