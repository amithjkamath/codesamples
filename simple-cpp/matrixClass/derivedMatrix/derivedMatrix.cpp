#include "derivedMatrix.h" // eat your own cooking.

#include "matrix.h" // if we are calling matrix functions.

derivedMatrix::derivedMatrix()
: matrix(1,1)
{
	setIsDiagonal(true);
	setDeterminant(0);
}

derivedMatrix::derivedMatrix(int x, int y, int value)
: matrix(x,y)
{
	setVal(x,y,value);
	setIsDiagonal(true);
	setDeterminant(0);
}

double derivedMatrix::getDeterminant()
{
	return determinant;
}

bool derivedMatrix::isDiagonal()
{
	return amIDiagonal;
}

derivedMatrix::~derivedMatrix()
{

}

//private functions.

void derivedMatrix::setIsDiagonal(bool x)
{
	amIDiagonal = x;
}

void derivedMatrix::setDeterminant(double det)
{
	determinant = det;
}
