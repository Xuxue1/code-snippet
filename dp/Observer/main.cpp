#include "Subject.h"
#include "Observer.h"

int main( int argc, char* argv[] )
{
	ConcreteSubject* sub = new ConcreteSubject();
	Observer* o1 = new ConcreteObserverA( sub );
	Observer* o2 = new ConcreteObserverB( sub );
	
	sub->SetState( "Old" );
	sub->Notify();

	sub->SetState( "New" );
	sub->Notify();
	return 0;
}