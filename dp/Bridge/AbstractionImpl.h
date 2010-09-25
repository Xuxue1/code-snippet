#ifndef _ABSTRACTION_IMPL_H_
#define _ABSTRACTION_IMPL_H_

class AbstractionImpl
{
public:
	virtual ~AbstractionImpl();
	virtual void Operation() = 0;
protected:
	AbstractionImpl();
};

class ConcretrAbstractionImplA : public AbstractionImpl
{
public:
	ConcretrAbstractionImplA();
	~ConcretrAbstractionImplA();
	void Operation();
};

class ConcretrAbstractionImplB : public AbstractionImpl
{
	ConcretrAbstractionImplB();
	~ConcretrAbstractionImplB();
	void Operation();
};

#endif//_ABSTRACTION_IMPL_H_