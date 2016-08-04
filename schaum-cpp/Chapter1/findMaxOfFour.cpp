//findMaxOfFour.cpp
//Problem 1.1 from schaum
// build as g++ -o findMaxOfFour findMaxOfFour.cpp ../get.cpp
#include <iostream>
#include "../get.h"

int main(void)
{
	std::cout << "This program finds the maximum of four numbers entered." << std::endl;
	
	int first = get_int("Enter first number: ");
	int second = get_int("Enter second number: ");
	int third = get_int("Enter third number: ");
	int fourth = get_int("Enter fourth number: ");
	
	int largest = 0;
	
	if(first > second)
		if(third > fourth)
			if(first > third)
				largest = first;
			else
				largest = third;
		else
			if(first > fourth)
				largest = first;
			else
				largest = fourth;
	else
		if(third > fourth)
			if(second > third)
				largest = second;
			else
				largest = third;
		else
			if(second > fourth)
				largest = second;
			else
				largest = fourth;

	std::cout << "The largest number is " << largest << std::endl;
	return 0;
}