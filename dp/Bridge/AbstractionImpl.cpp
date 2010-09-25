#include "AbstractionImpl.h"
#include <iostream>

using namespace std;

AbstractionImpl::AbstractionImpl()
{}

AbstractionImpl::~AbstractionImpl()
{}

void AbstractionImpl::Operation()
{
	cout << "AbstractionImpl..imp..." << endl;
}

ConcretrAbstractionImplA::ConcretrAbstractionImplA()
{}

ConcretrAbstractionImplA::~ConcretrAbstractionImplA()
{}

void ConcretrAbstractionImplA::Operation()
{
	cout << "ConcretrAbstractionImplA...imp" << endl;
}

ConcretrAbstractionImplB::ConcretrAbstractionImplB()
{}

ConcretrAbstractionImplB::~ConcretrAbstractionImplB()
{}

void ConcretrAbstractionImplB::Operation()
{
	cout << "ConcretrAbstractionImplB...imp" << endl;
}
