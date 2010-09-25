#ifndef _FLYWEIGHT_H_
#define _FLYWEIGHT_H_

#include <string>
using namespace std;

class Flyweight
{
public:
	virtual ~Flyweight();
	virtual void Operation( const string& extrinsicState );
	string GetIntrnsicState();
	Flyweight( string intrnsicState );
private:
	string _intrnsicState;
};

class ConcreteFlyweight : public Flyweight
{
public:
	ConcreteFlyweight( string intrnsicState );
	~ConcreteFlyweight();
	void Operation( const string& extrinsicState );
};
#endif//_FLYWEIGHT_H_