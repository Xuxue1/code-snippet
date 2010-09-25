#include "Product.h"
#include "Director.h"
#include "Builder.h"

int main( int argc, char* argv[] )
{
	Builder* b =   new ConcreteBuilder();
	Director* d = new Director(b);
	d->Construct();
	b->GetProduct();

	return 0;
}