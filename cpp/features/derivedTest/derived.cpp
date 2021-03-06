#include "derived.h"
#include "base.h"

#include <iostream>

derived::derived()
{
	//can call protected variables from base class here.
	_name = "derived";
	myValue = 0;
}

derived::derived(int inValue)
{
	_name = "derived:value";
	myValue = inValue;
}

void derived::print()
{
	//can call base member functions with the base:: specifier.
	base::print();
	std::cout << myValue << std::endl;
}
