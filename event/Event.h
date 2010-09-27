#ifndef _EVENT_H_
#define _EVENT_H_
class CEvent
{
public:
    typedef unsigned char TEventId;
    CEvent(const TEventId eventId);
    CEvent(const CEvent& ev);
    virtual ~CEvent();
private:
    /**
      * Default constructor
     */
    CEvent();
    CEvent& operator=(const CEvent& ev);
    const CEvent::TEventId CEvent::getEventId() const
    {
        return m_eventId;
    }

    const TEventId  m_eventId;
}

#endif
