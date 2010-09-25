#include <iostream>
#include "Adapter.h"

using namespace std;

Target::Target()
{}

Target::~Target()
{}

void Target::Request()
{
	cout << "Target...Request" << endl;
}

Adaptee::Adaptee()
{}

Adaptee::~Adaptee()
{}

void Adaptee::SpecificRequest()
{
	cout << "Adaptee...SpecificRequest" << endl;
}

#if CLASS
Adapter::Adapter()
{}

Adapter::~Adapter()
{}

void Adapter::Request()
{
	this->SpecificRequest();
}

#else
Adapter::Adapter( Adaptee* ade )
{
	this->_ade = ade;
}

Adapter::~Adapter()
{}

void Adapter::Request()
{
	_ade->SpecificRequest();
}
#endif