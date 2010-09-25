#include "FlyWeight.h"
#include <iostream>

using namespace std;

Flyweight::Flyweight( string intrnsicState )
:_intrnsicState(intrnsicState)
{}

Flyweight::~Flyweight()
{}

void Flyweight::Operation(const std::string &extrinsicState)
{

}

string Flyweight::GetIntrnsicState()
{
	return _intrnsicState;
}

ConcreteFlyweight::ConcreteFlyweight(std::string intrnsicState)
:Flyweight( intrnsicState )
{
	cout << "ConcreteFlyweight Build..." << intrnsicState << endl;
}

ConcreteFlyweight::~ConcreteFlyweight()
{

}

void ConcreteFlyweight::Operation(const std::string &extrinsicState)
{
	//cout << "ConcreteFlyweight:
	//	["<<this->GetIntrnsicState()<<"]
	//["<<extrinsicState<<"]" << endl;
}