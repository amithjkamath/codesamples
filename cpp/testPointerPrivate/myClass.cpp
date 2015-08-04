#include "myClass.h"

myClass::myClass()
{
	myVal = 0;
}

myClass::~myClass()
{
//blank
}

int myClass::getVal()
{
	return myVal;
}

void myClass::setVal(int x)
{
	if(x > 0)
		myVal = x;
}

const int* myClass::getPtr() const
{
	return &myVal;
}