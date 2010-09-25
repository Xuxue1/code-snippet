#include <iostream>
#include "AbstacFactory.h"
#include "Product.h"

using namespace std;

int main( int argc, char* argv[] )
{
	AbstacFactory* cf1 = new ConcreteFactory1();
	cf1->CreateProductA();
	cf1->CreateProductB();

	AbstacFactory* cf2 = new ConcreteFactory2();
	cf2->CreateProductA();
	cf2->CreateProductB();

	return 0;
}