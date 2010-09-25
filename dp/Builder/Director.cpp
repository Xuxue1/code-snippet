#include "Builder.h"
#include "Director.h"

Director::Director(Builder* bld )
{
	_bld = bld;
}

Director::~Director()
{

}

void Director::Construct()
{
	_bld->BuildPartA("pre-defined");
	_bld->BuildPartB("pre-defined");
	_bld->BuildPartC("pre-defined");
}