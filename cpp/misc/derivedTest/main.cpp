#include "base.h"
#include "derived.h"

int main()
{
	base myBase("myBase");
	derived myDerived(5);

	base &rBase = myDerived;

	// This won't work, because base cannot substitute for derived.
	//derived &rDerived = myBase;

	myBase.print();

	rBase.print();
	return 0;
}
