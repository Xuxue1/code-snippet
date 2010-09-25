#include "Strategy.h"
#include <iostream>

using namespace std;

Stratety::Stratety()
{}
Stratety::~Stratety()
{}

ConcreteStrategyA::ConcreteStrategyA()
{}
ConcreteStrategyA::~ConcreteStrategyA()
{}
void ConcreteStrategyA::AlgorithmInterface()
{
	cout << "ConcreteStrategyA::AlgorithmInterface()" << endl;
}

ConcreteStrategyB::ConcreteStrategyB()
{}
ConcreteStrategyB::~ConcreteStrategyB()
{}
void ConcreteStrategyB::AlgorithmInterface()
{
	cout << "ConcreteStrategyB::AlgorithmInterface()" << endl;
}