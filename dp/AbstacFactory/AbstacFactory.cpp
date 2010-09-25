#include <iostream>
#include "AbstacFactory.h"
#include "Product.h"

using namespace std;

//AbstacFactory
AbstacFactory::AbstacFactory()
{}

AbstacFactory::~AbstacFactory()
{}

//ConcreteFactory1
ConcreteFactory1::ConcreteFactory1()
{}

ConcreteFactory1::~ConcreteFactory1()
{}

AbstacProductA* ConcreteFactory1::CreateProductA()
{
	return new ProductA1();
}

AbstacProductB* ConcreteFactory1::CreateProductB()
{
	return new ProductB1();
}

//ConcreteFactory2
ConcreteFactory2::ConcreteFactory2()
{}

ConcreteFactory2::~ConcreteFactory2()
{}

AbstacProductA* ConcreteFactory2::CreateProductA()
{
	return new ProductA2();
}

AbstacProductB* ConcreteFactory2::CreateProductB()
{
	return new ProductB2();
}