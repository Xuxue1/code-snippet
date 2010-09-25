#ifndef _STRATEGY_H_
#define _STRATEGY_H_

class Stratety
{
public:
	Stratety();
	virtual ~Stratety();
	virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Stratety
{
public:
	ConcreteStrategyA();
	~ConcreteStrategyA();
	void AlgorithmInterface();
};

class ConcreteStrategyB : public Stratety
{
public:
	ConcreteStrategyB();
	~ConcreteStrategyB();
	void AlgorithmInterface();
};

#endif//_STRATEGY_H_