#include <iostream> // for std::cout
#include "fraction.h" // for fraction.

int main()
{
	fraction f1(1,2);
	f1.display();
	
	fraction f2(2,3);
	f2.display();
	
	if(f1 == f2)
	{
		std::cout << "Equal" << std::endl;
	}
	else
	{
		std::cout << "Not Equal" << std::endl;
	}
	
	f1.setNum(4);
	f1.setDen(6);
	
	if(f1 == f2)
	{
		std::cout << "Equal" << std::endl;
	}
	else
	{
		std::cout << "Not Equal" << std::endl;
	}	
	
	fraction f3;
	f3 = f1 + f2;
	f3.display();
	return 0;
}