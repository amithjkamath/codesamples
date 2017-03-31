#include <cmath>
#include "sdcalc.hpp"

double sdcalc(double* inArray, int numElems)
{
	double result = 0;
	double mean = 0;
	// calculate mean
	for(int i = 0; i < numElems; i++)
	{
		mean += inArray[i];
	}
	
	mean /= numElems;
	
	//sum of square errors	
	for(int j = 0; j < numElems; j++)
	{
		result += (inArray[j] - mean)*(inArray[j] - mean);
	}
	
	// square root, and divide by numElems
	result = sqrt(result/(numElems - 1));
	
	return result;
}
