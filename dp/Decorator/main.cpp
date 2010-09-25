#include <iostream>
#include "Decorator.h"

using namespace std;

int main( int argc, char*argv[] )
{
	Conponent* com = new ConcreteConponent();
	Decorator* dec = new ConcreteDecorator( com );
	dec->Operation();
	
	delete dec;
	return 0;
}