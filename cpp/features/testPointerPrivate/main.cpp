#include<iostream>
#include "myClass.h"

int main(void)
{
	myClass thisClass;
	thisClass.setVal(3);
	std::cout << "myVal is " << thisClass.getVal() << std::endl;
	
	const int* ptrInt = thisClass.getPtr();
	
	//*ptrInt = 5;
	
	std::cout << "myVal is " << thisClass.getVal() << std::endl;
	
	//*ptrInt = 6;
	
	std::cout << "myVal is " << *ptrInt << std::endl;
	
	return 0;
}