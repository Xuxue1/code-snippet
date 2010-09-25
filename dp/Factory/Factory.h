#ifndef _FACTORY_H_
#define _FACTORY_H_

class Product;

class Factory
{
public:
	virtual ~Factory() = 0;
	virtual Product* CreateProduct() = 0;
protected:
	Factory();
};

class ConcreteFactoryA :public Factory
{
public:
	ConcreteFactoryA();
	~ConcreteFactoryA();

	Product* CreateProduct();
};

class ConcreteFactoryB :public Factory
{
public:
	ConcreteFactoryB();
	~ConcreteFactoryB();

	Product* CreateProduct();
};

#endif//_FACTORY_H_