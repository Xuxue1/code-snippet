#include "Template.h"

int main( int argc, char* argv[] )
{
	AbstractClass* p1 = new ConcreteClassA();
	AbstractClass* p2 = new ConcreteClassB();
	p1->TemplateMethod();
	p2->TemplateMethod();

	return 0;
}