#include "FlyWeight.h"
#include "FlyweightFactory.h"

int main( int argc, char*argv[] )
{
	FlyweightFactory* fwf = new FlyweightFactory();
	Flyweight* fw1 = fwf->GetFlyweight( "Hello" );
	Flyweight* fw2 = fwf->GetFlyweight( "World" );
	Flyweight* fw3 = fwf->GetFlyweight( "Hello" );

	return 0;
}