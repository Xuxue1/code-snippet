#include "Adapter.h"
#include <iostream>

using namespace std;

int main( int argc, char* argv[] )
{
#if CLASS
	Adaptee* ade = new Adaptee();
	Adapter* adt = new Adapter();
	adt->Request();
#else
	Adaptee* ade = new Adaptee();
	Adapter* adt = new Adapter( ade );
	adt->Request();
#endif
	return 0;
}