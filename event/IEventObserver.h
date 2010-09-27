#ifndef _IEVENTOBSERVER_H_
#define _IEVENTOBSERVER_H_
#include "Event.h"
class IEventObserver
{
public :
   /**
    * Raise an event and return(async call)
    *
    * @param
    */
    virtual void RaiseEvent(const ) = 0
   /**
    * Generate and Handle an event(sync call)
    *
    * @param "aEvent" "The event to be handled."
    */
    virtual void HandleEvent(const ) = 0;
};


#endif