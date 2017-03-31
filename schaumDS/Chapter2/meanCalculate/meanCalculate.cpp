#include "meanCalculate.hpp"

void meanCalculate(double* numbers, int numElems, double* result)
{
	*result = 0;
	for(int i = 0; i < numElems; i++)
	{
		*result += numbers[i];
	}
	
	*result /= numElems;
}
