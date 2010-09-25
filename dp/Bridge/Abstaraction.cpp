#include <iostream>
#include "Abstraction.h"
#include "AbstractionImpl.h"

using namespace std;

Abstraction::Abstraction()
{}

Abstraction::~Abstraction()
{}

RefinedAbstraction::RefinedAbstraction( AbstractionImpl* imp )
{
	_imp = imp;
}

RefinedAbstraction::~RefinedAbstraction()
{

}

void RefinedAbstraction::Operation()
{
	_imp->Operation();
}