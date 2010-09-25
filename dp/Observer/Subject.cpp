#include "Subject.h"
#include "Observer.h"
#include <iostream>
#include <list>

using namespace std;



Subject::Subject()
{
	_obvs = new list<Observer*>;
}

Subject::~Subject()
{

}

void Subject::Attach(Observer *obv)
{
	_obvs->push_front( obv );
}

void Subject::Detach(Observer *obv)
{
	if ( obv != NULL )
	{
		_obvs->remove( obv );
	}
}

void Subject::Notify()
{
	list<Observer*>::iterator it = _obvs->begin();
	for ( ; it != _obvs->end(); ++it )
	{
		(*it)->Update(this);
	}
}

ConcreteSubject::ConcreteSubject()
{

}

ConcreteSubject::~ConcreteSubject()
{
	_st = '\0';
}

State ConcreteSubject::GetState()
{
	return _st;
}

void ConcreteSubject::SetState(const State &st)
{
	_st = st;
}