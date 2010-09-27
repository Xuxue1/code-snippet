#ifndef _QUEUE_H_
#define _QUEUE_H_

#ifdef _MT
#include <process.h>
#endif
#include <windows.h>
typedef struct queue_tag  /* General purpose queue  */
{   
    HANDLE  q_guard;/* Guard the message block  */
    HANDLE  q_ne;   /* Event: Queue is not empty        */
    HANDLE  q_nf;   /* Event: Queue is not full         */
                    /* These two events are manual-reset for the broadcast model
                     * and auto-reset for the signal model */
    volatile DWORD q_size;  /* Queue max size size      */
    volatile DWORD q_first; /* Index of oldest message  */
    volatile DWORD q_last;  /* Index of youngest msg    */
    volatile DWORD q_destroyed;/* Q receiver has terminated */
    PVOID   msg_array;  /* array of q_size messages */
} queue_t;

/* Queue management functions */
DWORD q_initialize (queue_t *, DWORD, DWORD);
DWORD q_destroy (queue_t *);
DWORD q_destroyed (queue_t *);
DWORD q_empty (queue_t *);
DWORD q_full (queue_t *);
DWORD q_get (queue_t *, PVOID, DWORD, DWORD);
DWORD q_put (queue_t *, PVOID, DWORD, DWORD);
DWORD q_remove (queue_t *, PVOID, DWORD);
DWORD q_insert (queue_t *, PVOID, DWORD);
#endif