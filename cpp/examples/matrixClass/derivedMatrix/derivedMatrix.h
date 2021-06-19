#ifndef DERIVEDMATRIX_HEADER
#define DERIVEDMATRIX

#include "matrix.h"

// derived class from matrix, only 2 x 2 allowed. 
// also holds determinant, and a boolean for is diagonal.

class derivedMatrix : public matrix
{
	public:
		derivedMatrix();
		derivedMatrix(int x, int y, int value);

		double getDeterminant();
		bool isDiagonal();

		~derivedMatrix();

	private:
		void setIsDiagonal(bool x);
		void setDeterminant(double det);

		bool amIDiagonal;
		double determinant;
};

#endif
