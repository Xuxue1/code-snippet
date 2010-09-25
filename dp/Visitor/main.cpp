#include "Element.h"
#include "Visitor.h"

int main( int argc, char* argv[] )
{
	Visitor* vis = new ConcreteVisitorA();
	Element* elm = new ConcreteElementA();
	elm->Accept( vis );
	return 0;
}