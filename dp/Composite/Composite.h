#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_

#include "Component.h"
#include <vector>
using namespace std;

class Composite : public Component
{
public:
	Composite();
	~Composite();

public:
	void Operation();
	void Add( Component* );
	void Remove( Component* );
	Component* GetChild(int index);
private:
	vector<Component*> comVec;
};
#endif//_COMPOSITE_H_