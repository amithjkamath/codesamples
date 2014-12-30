//sumnaverage.cpp
// build as g++ -o sumnaverage sumnaverage.cpp ../get.cpp
#include <iostream>
#include "../get.h"

int main(void)
{
	//Print some information about this program.
	std::cout << "This program takes as input, an array of numbers, and outputs its sum and average. Please enter numbers at the prompt: " << std::endl;
	
	double inNum = 0;
	double sumVal = 0;
	int n = 0;
	
	// this is to setup the termination condition.
	double minVal = get_double("Enter the minimum possible number: ");
	std::cout << "Enter " << minVal - 1 << " or lesser to terminate." << std::endl;
	
	inNum = get_double("Enter number: ");
	
	//loop through the numbers, until termination condition is hit.
	while(inNum >= minVal)
	{
		n++;
		sumVal+= inNum;
		inNum = get_double("Enter number: ");
	}
	
	//print out the statistics.
	std::cout << "The sum of all entered numbers is: " << sumVal << std::endl;
	if(n != 0)
		std::cout << "The average of all entered numbers is: " << sumVal/n << std::endl;
	else
		std::cout << "The average of all entered numbers is not defined." << std::endl; //case when first element is minVal
	
	return 0;
}