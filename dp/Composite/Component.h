#ifndef _COMPONENT_H_
#define _COMPONENT_H_

class Component
{
public:
	Component();
	virtual ~Component();
public:
	virtual void Operation() = 0;
	virtual void Add(  Component* );
	virtual void Remove(  Component* );
	virtual Component* GetChild( int );
};
#endif//_COMPONENT_H_