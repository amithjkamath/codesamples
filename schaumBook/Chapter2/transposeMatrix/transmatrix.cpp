#include <cmath>
#include "transmatrix.hpp"

void transmatrix(double inMatrix, int numRows, int numCols, double outMatrix)
{
	// loop through and transpose input.
	for(int i = 0; i < numRows; i++)
	{
		for(int j = 0; j < numCols; j++)
		{
			outMatrix[j][i] = inMatrix[i][j];
		}
	}
}

