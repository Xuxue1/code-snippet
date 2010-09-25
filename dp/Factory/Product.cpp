#include <iostream>
#include "Product.h"

using namespace std;

Product::Product()
{}

Product::~Product()
{}


ConcreteProductA::ConcreteProductA()
{
	cout << "ConcreteProductA..." << endl;
}

ConcreteProductA::~ConcreteProductA()
{

}

ConcreteProductB::ConcreteProductB()
{
	cout <<"ConcreteProductB..." << endl;
}

ConcreteProductB::~ConcreteProductB()
{

}