#include "Context.h"
#include <iostream>

Context::Context(Stratety *sty)
:_sty(sty)
{}

Context::~Context()
{
	if ( _sty != NULL )
	{
		delete _sty;
		_sty = NULL;
	}
}

void Context::DoAction()
{
	_sty->AlgorithmInterface();
}