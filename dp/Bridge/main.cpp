#include <iostream>
#include "Abstraction.h"
#include "AbstractionImpl.h"

using namespace std;

int main( int argc, char* argv[] )
{
	AbstractionImpl* imp = new ConcretrAbstractionImplA();
	Abstraction* abs = new RefinedAbstraction( imp );
	abs->Operation();
	return 0;
}