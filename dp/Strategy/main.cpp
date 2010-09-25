#include "Context.h"
#include "Strategy.h"
#include <iostream>

int main( int argc, char* argv[] )
{
	Stratety* ps = new ConcreteStrategyA();
	Context* pc = new Context( ps );
	pc->DoAction();
	if ( pc != NULL )
	{
		delete pc;
		pc = NULL;
	}
	return 0;
}