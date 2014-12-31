#include <iostream>
#include <cstdlib> // for exit
#include <iomanip> // for setprecision and setw

#include "matrix.h" //eat your own cooking.

#define MAXSIZE 200 //maximum dimension of matrix currently supported.

matrix::matrix(int x, int y)
{
	numRows(x);
	numCols(y);
	myElements = new double*[x];
	for (int i = 0; i < getNumRows(); ++i){
    	myElements[i] = new double[y];
	}	
	setToZero();
}

int matrix::getNumRows() const
{
	return rows;
}

int matrix::getNumCols() const
{
	return cols;
}

void matrix::setToZero()
{
	for(int i = 0; i < getNumRows(); i++){
		for(int j = 0; j < getNumCols(); j++){
			setVal(0.0,i,j);
		}
	}
}
	
bool matrix::isZero()
{
	for(int i = 0; i < getNumRows(); i++){
		for(int j = 0; j < getNumCols(); j++){
			if(getVal(i,j) != 0)
			{
				return false;				
			}
		}
	}
	return true;
}
	
void matrix::setVal(double val, int x, int y)
{
	//input validation.
	if(x < 0 || x >= getNumRows())
	{
		std::cerr << "Error: " << x 
		<< " is invalid. The number of rows is " 
		<< getNumRows() << std::endl;
		exit(1); 
	}
	if(y < 0 || y >= getNumCols())
	{
		std::cerr << "Error: " << y 
		<< " is invalid. The number of columns is " 
		<< getNumCols() << std::endl;
		exit(1); 
	}
	myElements[x][y] = val;
}

double matrix::getVal(int x, int y) const
{
	//input validation.
	if(x < 0 || x >= getNumRows())
	{
		std::cerr << "Error: " << x 
		<< " is invalid. The number of rows is " 
		<< getNumRows() << std::endl;
		exit(1); 
	}
	if(y < 0 || y >= getNumCols())
	{
		std::cerr << "Error: " << y 
		<< " is invalid. The number of columns is " 
		<< getNumCols() << std::endl;
		exit(2); 
	}
	return myElements[x][y];
}

void matrix::numRows(int n)
{
	if(n > 0 && n < MAXSIZE)
	{
		rows = n;
	}
	else
	{
		std::cerr << "Invalid Rows: " << n << std::endl;
		exit(3);
	}
}

void matrix::numCols(int n)
{
	if(n > 0 && n < MAXSIZE)
	{
		cols = n;
	}
	else
	{
		std::cerr << "Invalid Columns: " << n << std::endl;
		exit(4);
	}
}

void matrix::display() const
{
	std::cout << "Number of Rows: " << getNumRows() << std::endl;
	std::cout << "Number of Cols: " << getNumCols() << std::endl;
	{	
		std::cout << "[" << std::endl;
		std::cout << std::setw(3);
		std::cout << std::setprecision(3);
		for(int i = 0; i < getNumRows(); i++){
			for(int j = 0; j < getNumCols(); j++){
				std::cout << getVal(i,j) << " , ";
			}
			std::cout << std::endl;
		}
		std::cout << "]" << std::endl;
	}
}

matrix matrix::operator+(const matrix& other)
{
	if((getNumRows() != other.getNumRows()) || (getNumCols() != other.getNumCols()))
	{
		std::cerr << "Matrices not same dimension for addition." << std::endl;
		exit(5);	
	}
	matrix res(getNumRows(),getNumCols());
	for(int i = 0; i < res.getNumRows(); i++){
		for(int j = 0; j < res.getNumCols(); j++){
			res.setVal(this->getVal(i,j) + other.getVal(i,j),i,j);
		}
	}
	return res;
}

matrix matrix::operator-(const matrix& other)
{
	if((getNumRows() != other.getNumRows()) || (getNumCols() != other.getNumCols()))
	{
		std::cerr << "Matrices not same dimension for subtraction." << std::endl;
		exit(6);	
	}
	matrix res(getNumRows(),getNumCols());
	for(int i = 0; i < res.getNumRows(); i++){
		for(int j = 0; j < res.getNumCols(); j++){
			double myX = getVal(i,j);
			double otherX = other.getVal(i,j);
			res.setVal(myX - otherX,i,j);
		}
	}
	return res;
}

matrix matrix::operator*(const matrix& other)
{
	if((getNumRows() != other.getNumRows()) || (getNumCols() != other.getNumCols()))
	{
		std::cerr << "Matrices not same dimension for multiplication." << std::endl;
		exit(7);	
	}
	matrix res(getNumRows(),getNumCols());
	for(int i = 0; i < res.getNumRows(); i++){
		for(int j = 0; j < res.getNumCols(); j++){
			double myX = getVal(i,j);
			double otherX = other.getVal(i,j);
			res.setVal(myX*otherX,i,j);
		}
	}
	return res;
}

matrix matrix::operator*(double val)
{
	matrix res(getNumRows(),getNumCols());
	for(int i = 0; i < res.getNumRows(); i++){
		for(int j = 0; j < res.getNumCols(); j++){
			double myX = getVal(i,j);			
			res.setVal(myX*val,i,j);
		}
	}
	return res;
}

matrix operator*(double num, matrix& mat)
{
	matrix res(mat.getNumRows(),mat.getNumCols());
	for(int i = 0; i < res.getNumRows(); i++){
		for(int j = 0; j < res.getNumCols(); j++){
			double myX = mat.getVal(i,j);			
			res.setVal(myX*num,i,j);
		}
	}
	return res;
}

// this is an ambiguous overload.
/*
matrix operator*(matrix& mat, double num)
{
	matrix res(mat.getNumRows(),mat.getNumCols());
	for(int i = 1; i <= mat.getNumRows(); i++){
		for(int j = 1; j <= mat.getNumCols(); j++){
			double myX = mat.getVal(i,j);			
			res.setVal(myX*num,i,j);
		}
	}
	return res;
}
*/

matrix::~matrix()
{
	std::cout << "Destructing matrix." << std::endl;
	//delete[] myElements;
}
