#ifndef _BUILDER_H_
#define _BUILDER_H_

#include <string>
using namespace std;

class Product;

class Builder
{
public:
	virtual ~Builder();
	virtual void BuildPartA( const string& buildPara ) = 0;
	virtual void BuildPartB( const string& buildPara ) = 0;
	virtual void BuildPartC( const string& buildPara ) = 0;
	Product* GetProduct();
protected:
	Builder();
protected:
	Product* _product;
};

class ConcreteBuilder :public Builder
{
public:
	ConcreteBuilder();
	~ConcreteBuilder();
	void BuildPartA(const string& buildPara );
	void BuildPartB(const string& buildPara );
	void BuildPartC(const string& buildPara );
	Product* GetProduct();
};
#endif//_BUILDER_H_