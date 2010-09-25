#include "Component.h"
#include "Composite.h"
#include <algorithm>

Composite::Composite()
{}

Composite::~Composite()
{}

void Composite::Operation()
{
	vector<Component*>::iterator comIter = comVec.begin();
	for ( ; comIter != comVec.end(); ++comIter )
	{
		(*comIter)->Operation();
	}
}

void Composite::Add( Component* com)
{
	comVec.push_back( com );
}

void Composite::Remove( Component* com )
{
	std::remove( comVec.begin(), comVec.end(), com );
}

Component* Composite::GetChild(int index)
{
	return comVec[index];
}