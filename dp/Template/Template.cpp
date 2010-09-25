#include "Template.h"
#include <iostream>

using namespace  std;

AbstractClass::AbstractClass()
{}

AbstractClass::~AbstractClass()
{}

void AbstractClass::TemplateMethod()
{
	Primitive1();
	Primitive2();
}

ConcreteClassA::ConcreteClassA()
{}

ConcreteClassA::~ConcreteClassA()
{}

void ConcreteClassA::Primitive1()
{
	cout << "ConcreteClassA::Primitive1()" << endl;
}

void ConcreteClassA::Primitive2()
{
	cout << "ConcreteClassA::Primitive2()" << endl;
}

ConcreteClassB::ConcreteClassB()
{}

ConcreteClassB::~ConcreteClassB()
{}

void ConcreteClassB::Primitive1()
{
	cout << "ConcreteClassB::Primitive1()" << endl;
}

void ConcreteClassB::Primitive2()
{
	cout << "ConcreteClassB::Primitive2()" << endl;
}