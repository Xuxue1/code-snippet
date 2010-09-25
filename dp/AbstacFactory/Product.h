#ifndef _PRODUCT_H_
#define _PRODUCT_H_

class AbstacProductA
{
public:
	virtual ~AbstacProductA();
protected:
	AbstacProductA();
};

class AbstacProductB
{
public:
	virtual ~AbstacProductB();
protected:
	AbstacProductB();
};

class ProductA1 :public AbstacProductA
{
public:
	ProductA1();
	~ProductA1();
};

class ProductA2 :public AbstacProductA
{
public:
	ProductA2();
	~ProductA2();
};

class ProductB1 :public AbstacProductB
{
public:
	ProductB1();
	~ProductB1();
};

class ProductB2 :public AbstacProductB
{
public:
	ProductB2();
	~ProductB2();
};
#endif//_PRODUCT_H_