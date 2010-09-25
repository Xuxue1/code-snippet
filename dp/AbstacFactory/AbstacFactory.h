#ifndef _ABSTADC_FACTORY_H_
#define _ABSTADC_FACTORY_H_

class AbstacProductA;
class AbstacProductB;

class AbstacFactory
{
public:
	virtual ~AbstacFactory();
	virtual AbstacProductA* CreateProductA() = 0;
	virtual AbstacProductB* CreateProductB() = 0;
protected:
	AbstacFactory();
};

class ConcreteFactory1 :public AbstacFactory
{
public:
	ConcreteFactory1();
	~ConcreteFactory1();
	AbstacProductA* CreateProductA();
	AbstacProductB* CreateProductB();
};

class ConcreteFactory2 :public AbstacFactory
{
public:
	ConcreteFactory2();
	~ConcreteFactory2();
	AbstacProductA* CreateProductA();
	AbstacProductB* CreateProductB();
};

#endif//_ABSTADC_FACTORY_H_