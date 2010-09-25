#ifndef _FLYWEIGHT_FACTORY_H_
#define _FLYWEIGHT_FACTORY_H_

#include "FlyWeight.h"
#include <vector>
#include <string>
using namespace std;

class FlyweightFactory
{
public:
	FlyweightFactory();
	~FlyweightFactory();
	Flyweight* GetFlyweight( const string& key );
private:
	vector<Flyweight*> _fly;
};
#endif//_FLYWEIGHT_FACTORY_H_