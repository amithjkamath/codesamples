#include <iostream> // for std::cerr
#include <cstdlib> // for exit

#include "fraction.h"

//constructors
fraction::fraction(int numVal, int denVal)
{
	setNum(numVal);
	setDen(denVal);
	reduce();
}

//getters and setters
void fraction::setNum(int val)
{
	myNum = val;
}
	
int fraction::getNum() const
{
	return myNum;
}
	
void fraction::setDen(int val)
{
	if(val != 0)
	{
		myDen = val;
	}
	else
	{
		std::cerr << "Error: denominator is 0." << std::endl;
		exit(2);
	}
}

int fraction::getDen() const
{
	return myDen;
}

void fraction::reduce()
{	
	if(getNum() != 0)
	{	
		// make arguments to gcd positive. 
		int numVal = (getNum() > 0) ? getNum() : -getNum();
		int denVal = (getDen() > 0) ? getDen() : -getDen();
		int gcdDen = gcd(numVal, denVal);
		// depending on sign of denominator, set up new values of num and den.
		if(getDen() < 0)
		{
			setNum(-getNum()/gcdDen);		
			setDen(-getDen()/gcdDen);
		}
		else
		{
			setNum(getNum()/gcdDen);
			setDen(getDen()/gcdDen);
		}
	}
	else
	{
		setNum(0);
		setDen(1);
	}
}

void fraction::display() const
{
	std::cout << "Fraction is: " << getNum() << "/" << getDen() << std::endl;
}

//destructor
fraction::~fraction()
{

}

// independent functions

// arithmetic functions.
fraction operator+(const fraction& fracOne, const fraction& fracTwo)
{
	fraction fracOut;
	fracOut.setNum((fracOne.getNum()*fracTwo.getDen())
	+ (fracTwo.getNum()*fracOne.getDen()));
	fracOut.setDen(fracOne.getDen()*fracTwo.getDen());
	fracOut.reduce();
	return fracOut;
}

fraction operator-(const fraction& fracOne, const fraction& fracTwo)
{
	fraction fracOut;
	fracOut.setNum((fracOne.getNum()*fracTwo.getDen()) 
	- (fracTwo.getNum()*fracOne.getDen()));
	fracOut.setDen(fracOne.getDen()*fracTwo.getDen());
	fracOut.reduce();
	return fracOut;
}

fraction operator*(const fraction& fracOne, const fraction& fracTwo)
{
	fraction fracOut;
	fracOut.setNum(fracOne.getNum()*fracTwo.getNum());
	fracOut.setDen(fracOne.getDen()*fracTwo.getDen());
	fracOut.reduce();
	return fracOut;
}

fraction operator/(const fraction& fracOne, const fraction& fracTwo)
{
	fraction fracOut;
	fracOut.setNum(fracOne.getNum()*fracTwo.getDen());
	fracOut.setDen(fracOne.getDen()*fracTwo.getNum());
	fracOut.reduce();
	return fracOut;
}

// comparison functions.

bool operator==(const fraction& fracOne, const fraction& fracTwo)
{
	fraction fracOut;
	fracOut = fracOne - fracTwo;
	return (fracOut.getNum() == 0);
}

bool operator!=(const fraction& fracOne, const fraction& fracTwo)
{
	// use the == overload, to define the inverse case.
	return !(fracOne == fracTwo);
}

bool operator>(const fraction& fracOne, const fraction& fracTwo)
{
	fraction fracOut;
	fracOut = fracOne - fracTwo;
	return (fracOut.getNum() > 0);
}

bool operator<(const fraction& fracOne, const fraction& fracTwo)
{
	//  be consistent with the > function, and use it here.
	return !(fracOne > fracTwo);
}

// independent function: Euclid's GCD function.

// algorithm from Wikipedia.
int gcd(int x, int y)
{
	if(x < 1 || y < 1)
	{
		std::cerr << "Numbers are invalid for gcd. Expect only positive numbers." 
		<< std::endl;
		exit(1);
	}
    while (x != y)
    {
       if (x < y)
          y = y - x;
       else
          x = x - y;
    }
    return x;
}
