#ifndef _DECORATOR_H_
#define _DECORATOR_H_

class Conponent
{
public:
	virtual ~Conponent();
	virtual void Operation();
protected:
	Conponent();
};

class Decorator: public Conponent
{
public:
	Decorator( Conponent* com );
	virtual ~Decorator();
	void Operation();
protected:
	Conponent* _com;
};

class ConcreteConponent : public Conponent
{
public:
	ConcreteConponent();
	~ConcreteConponent();
	void Operation();
};

class ConcreteDecorator : public Decorator
{
public:
	ConcreteDecorator( Conponent* com );
	~ConcreteDecorator();
	void Operation();
	void AddedBehavior();
};
#endif//_DECORATOR_H_