#include <iostream>
#include "Builder.h"
#include "Product.h"

using namespace std;

Builder::Builder()
{

}
Builder::~Builder()
{

}

Product* Builder::GetProduct()
{
	return _product;
}

ConcreteBuilder::ConcreteBuilder()
{
	_product = new Product();
}

ConcreteBuilder::~ConcreteBuilder()
{

}

void ConcreteBuilder::BuildPartA(const std::string &buildPara)
{
	cout << "Step1:BuildPartA..." << buildPara << endl;
	_product->SetPartA();
}

void ConcreteBuilder::BuildPartB(const std::string &buildPara)
{
	cout << "Step1:BuildPartB..." << buildPara << endl;
	_product->SetPartB();
}

void ConcreteBuilder::BuildPartC(const std::string &buildPara)
{
	cout << "Step1:BuildPartC..." << buildPara << endl;
	_product->SetPartC();
}
