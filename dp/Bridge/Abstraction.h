#ifndef _ABSTRACTION_H_
#define _ABSTRACTION_H_

class AbstractionImpl;

class Abstraction
{
public:
	virtual ~Abstraction();
	virtual void Operation() = 0;
protected:
	Abstraction();
};

class RefinedAbstraction : public Abstraction
{
public:
	RefinedAbstraction( AbstractionImpl* imp );
	~RefinedAbstraction();
	void Operation();
private:
	AbstractionImpl* _imp;
};

#endif//_ABSTRACTION_H_