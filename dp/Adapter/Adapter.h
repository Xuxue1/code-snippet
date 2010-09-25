#ifndef _ADAPTER_CLASS_H_
#define _ADAPTER_CLASS_H_

#define  CLASS 0
#define  OBJECT 0

class Target
{
public:
	Target();
	~Target();
	virtual void Request();
};

class Adaptee
{
public:
	Adaptee();
	~Adaptee();
	void SpecificRequest();
};

#if CLASS
class Adapter : public Target, private Adaptee
{
public:
	Adapter();
	~Adapter();
	void Request();
};

#else 

class Adapter : public Target
{
public:
	Adapter( Adaptee* ade );
	~Adapter();
	void Request();
private:
	Adaptee* _ade;
};
#endif

#endif//_ADAPTER_CLASS_H_