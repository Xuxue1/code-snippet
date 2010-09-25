#include <iostream>
#include "Decorator.h"

using namespace std;

Conponent::Conponent()
{}

Conponent::~Conponent()
{}

void Conponent::Operation()
{}

ConcreteConponent::ConcreteConponent()
{}

ConcreteConponent::~ConcreteConponent()
{}

void ConcreteConponent::Operation()
{
	cout << "ConcreteConponent::Operation" << endl;
}

Decorator::Decorator(Conponent *com)
{
	this->_com = com;
}

Decorator::~Decorator()
{
	delete _com;
}

void Decorator::Operation()
{
}

ConcreteDecorator::ConcreteDecorator(Conponent *com)
:Decorator( com )
{}

ConcreteDecorator::~ConcreteDecorator()
{}

void ConcreteDecorator::AddedBehavior()
{
	cout << "ConcreteDecorator::AddedBehavior" << endl;
}
void ConcreteDecorator::Operation()
{
	_com->Operation();
	this->AddedBehavior();
}