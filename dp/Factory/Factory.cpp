#include <iostream>
#include "Product.h"
#include "Factory.h"

using namespace std;

Factory::Factory()
{

}

Factory::~Factory()
{

}

ConcreteFactoryA::ConcreteFactoryA()
{
	cout << "ConcreteFactoryA..." << endl;
}

ConcreteFactoryA::~ConcreteFactoryA()
{

}

Product* ConcreteFactoryA::CreateProduct()
{
	return new ConcreteProductA();
}

ConcreteFactoryB::ConcreteFactoryB()
{
	cout << "ConcreteFactoryB..." << endl;
}

ConcreteFactoryB::~ConcreteFactoryB()
{

}

Product* ConcreteFactoryB::CreateProduct()
{
	return new ConcreteProductB();
}