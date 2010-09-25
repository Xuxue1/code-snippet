#include "FlyWeight.h"
#include "FlyweightFactory.h"
#include <iostream>
#include <string>

using namespace std;

FlyweightFactory::FlyweightFactory()
{

}

FlyweightFactory::~FlyweightFactory()
{

}

Flyweight* FlyweightFactory::GetFlyweight(const std::string &key)
{
	vector<Flyweight*>::iterator itBegin = _fly.begin();
	for ( ; itBegin != _fly.end(); ++itBegin )
	{
		if ( (*itBegin)->GetIntrnsicState()  == key )
		{
			cout << "already created by user..." << endl;
			return *itBegin;
		}
	}

	Flyweight* fn = new Flyweight( key );
	_fly.push_back( fn );
	return fn;
}