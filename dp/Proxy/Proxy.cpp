#include "Proxy.h"
#include <iostream>

using namespace std;

Subject::Subject()
{}

Subject::~Subject()
{}

RealSubject::RealSubject()
{}

RealSubject::~RealSubject()
{}

void RealSubject::Request()
{
	cout << "RealSubject::Request()" << endl;
}

Proxy::Proxy()
{}

Proxy::Proxy(Subject *sub)
:_sub(sub)
{}

Proxy::~Proxy()
{
	delete _sub;
}

void Proxy::Request()
{
	cout << "Proxy::Request()" << endl;
	_sub->Request();
}