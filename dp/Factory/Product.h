#ifndef _PRODUCT_H_
#define _PRODUCT_H_

class Product
{
public:
	virtual ~Product() = 0;
protected:
	Product();
};

class ConcreteProductA :public Product
{
public:
	ConcreteProductA();
	~ConcreteProductA();
};

class ConcreteProductB :public Product
{
public:
	ConcreteProductB();
	~ConcreteProductB();
};

#endif//_PRODUCT_H_