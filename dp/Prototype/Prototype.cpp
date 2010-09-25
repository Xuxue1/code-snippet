#include <iostream>
#include "Prototype.h"

using namespace std;

Prototype::Prototype()
{}

Prototype::~Prototype()
{}

Prototype* Prototype::Clone() const
{
	return 0;
}

ConcretePrototype::ConcretePrototype()
{}

ConcretePrototype::~ConcretePrototype()
{}

ConcretePrototype::ConcretePrototype(const ConcretePrototype &cp)
{
	cout << "ConcretePrototype Copy" << endl;
}

Prototype* ConcretePrototype::Clone() const
{
	return new ConcretePrototype( *this );
}