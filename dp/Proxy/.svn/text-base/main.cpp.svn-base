#include "Proxy.h"

int main( int arvc, char*agrv[] )
{
	Subject* sub = new RealSubject();
	Proxy* pro = new Proxy( sub );
	pro->Request();
	delete pro;
	return 0;
}