//testMonth.cpp
// build as g++ -o testMonth testMonth.cpp ../get.cpp
#include <iostream>
#include "../get.h"

int main(void)
{
	int monthArray[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	int inMonth = get_int("Please enter the month number: ");
	while(inMonth < 1 || inMonth > 12)
	{
		inMonth = get_int("Please enter a valid month number: ");
	}
	
	switch(inMonth)
	{
	case 1:
	std::cout << "Number of days in the " << inMonth << "st month is " << monthArray[inMonth-1] << std::endl; break;
	case 2:
	std::cout << "Number of days in the " << inMonth << "nd month is " << monthArray[inMonth-1] << " or " << monthArray[inMonth-1]+1 << std::endl; break;
	case 3:
	std::cout << "Number of days in the " << inMonth << "rd month is " << monthArray[inMonth-1] << std::endl; break;	
	default:
	std::cout << "Number of days in the " << inMonth << "th month is " << monthArray[inMonth-1] << std::endl;
	}
	return 0;
}