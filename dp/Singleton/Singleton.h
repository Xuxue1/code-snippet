#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>

using namespace std;

class Singleton
{
public:
	static Singleton* Instance();
private:
	Singleton();
	static Singleton* _instance;
};

#endif//_SINGLETON_H_