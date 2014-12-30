//findMedian.cpp
//Problem 1.2 from schaum
// build as g++ -o findMedian findMedian.cpp ../get.cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include "../get.h"

int main(void)
{
	std::cout << "This program finds the median of the five numbers entered." << std::endl;
	
	int array[5];
	array[0] = get_int("Enter first number: ");
	array[1] = get_int("Enter second number: ");
	array[2] = get_int("Enter third number: ");
	array[3] = get_int("Enter fourth number: ");
	array[4] = get_int("Enter fifth number: ");	
	
	std::vector<int> myVec(array, array+5);
	std::sort(myVec.begin(),myVec.end());
	
	std::cout << "The median value is " << myVec[2] << std::endl;
	return 0;
}