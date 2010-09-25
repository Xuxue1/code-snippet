#include "Facade.h"

Subsystem1::Subsystem1()
{}

Subsystem1::~Subsystem1()
{}

void Subsystem1::Operation()
{
	cout << "Subsystem1::Operation" << endl;
}

Subsystem2::Subsystem2()
{}

Subsystem2::~Subsystem2()
{}

void Subsystem2::Operation()
{
	cout << "Subsystem2::Operation" << endl;
}

Facade::Facade()
{
	s1 = new Subsystem1();
	s2 = new Subsystem2();
}

Facade::~Facade()
{}

void Facade::OperationWapper()
{
	cout << "Facade::Operation" << endl;
	s1->Operation();
	s2->Operation();
}