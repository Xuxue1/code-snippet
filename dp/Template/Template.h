#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

class AbstractClass
{
public:
	virtual ~AbstractClass();
	void TemplateMethod();
protected:
	AbstractClass();
	virtual void Primitive1() = 0;
	virtual void Primitive2() = 0;
};

class ConcreteClassA : public AbstractClass
{
public:
	ConcreteClassA();
	~ConcreteClassA();
protected:
	void Primitive1();
	void Primitive2();
};

class ConcreteClassB : public AbstractClass
{
public:
	ConcreteClassB();
	~ConcreteClassB();
protected:
	void Primitive1();
	void Primitive2();
};

#endif//_TEMPLATE_H_