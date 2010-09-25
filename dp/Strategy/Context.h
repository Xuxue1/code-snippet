#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include "Strategy.h"

class Context
{
public:
	Context( Stratety* sty );
	~Context();
	void DoAction();
private:
	Stratety* _sty;
};
#endif//_CONTEXT_H_