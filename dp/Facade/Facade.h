#ifndef _FACADE_H_
#define _FACADE_H_

#include <iostream>
using namespace std;

class Subsystem1
{
public:
	Subsystem1();
	~Subsystem1();
	void Operation();
};

class Subsystem2
{
public:
	Subsystem2();
	~Subsystem2();
	void Operation();
};

class Facade
{
public:
	Facade();
	~Facade();
	void OperationWapper();
private:
	Subsystem1* s1;
	Subsystem2* s2;
};
#endif//_FACADE_H_