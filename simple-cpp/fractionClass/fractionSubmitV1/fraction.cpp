#include <iostream> // for std::cerr
#include <cstdlib> // for exit

#include "fraction.h"

//constructors
fraction::fraction()
{
	//agree that this is the default.
	setNum(1);
	setDen(1);
}
	
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
		// the following four cases are to make the gcd function work with all	
		// possible positive/negative combinations of input numbers.
		if(getNum() > 0 && getDen() > 0)
		{		
			int gcdVal = gcd(getNum(),getDen());
			setNum(getNum()/gcdVal);
			setDen(getDen()/gcdVal);
		}
		if(getNum() > 0 && getDen() < 0)
		{		
			int gcdVal = gcd(getNum(),-getDen());
			// swap the sign to the numerator.			
			setNum(-getNum()/gcdVal);
			setDen(-getDen()/gcdVal);
		}
		if(getNum() < 0 && getDen() > 0)
		{		
			int gcdVal = gcd(-getNum(),getDen());
			setNum(getNum()/gcdVal);
			setDen(getDen()/gcdVal);
		}
		if(getNum() < 0 && getDen() < 0)
		{		
			// make the fraction positive.
			int gcdVal = gcd(-getNum(),-getDen());
			setNum(-getNum()/gcdVal);
			setDen(-getDen()/gcdVal);
		}
	}
	else
	{
		setNum(0);
		setDen(1);
	}
}

void fraction::display()
{
	std::cout << "Fraction is: " << getNum() << "/" << getDen() << std::endl;
}

// friend functions

// arithmetic functions.
fraction operator+(const fraction& fracOne, const fraction& fracTwo)
{
	fraction fracOut;
	int gcdOut = gcd(fracOne.getDen(), fracTwo.getDen());
	fracOut.setNum((fracOne.getNum()*fracTwo.getDen()) + (fracTwo.getNum()*fracOne.getDen()));
	fracOut.setDen(fracOne.getDen()*fracTwo.getDen());
	fracOut.reduce();
	return fracOut;
}

fraction operator-(const fraction& fracOne, const fraction& fracTwo)
{
	fraction fracOut;
	int gcdOut = gcd(fracOne.getDen(), fracTwo.getDen());
	fracOut.setNum((fracOne.getNum()*fracTwo.getDen()) - (fracTwo.getNum()*fracOne.getDen()));
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
	if(fracOut.getNum() == 0)
		return true;
	else
		return false;
}

bool operator!=(const fraction& fracOne, const fraction& fracTwo)
{
	// use the == overload, to define the inverse case.
	if(fracOne == fracTwo)
		return false;
	else
		return true;
}

bool operator>(const fraction& fracOne, const fraction& fracTwo)
{
	fraction fracOut;
	fracOut = fracOne - fracTwo;
	if(fracOut.getNum() > 0)
		return true;
	else
		return false;
}

bool operator<(const fraction& fracOne, const fraction& fracTwo)
{
	//  be consistent with the > function, and use it here.
	if(fracOne > fracTwo)
		return false;
	else
		return true;
}

//destructor
fraction::~fraction()
{

}

// independent function: Euclid's GCD function.
// algorithm from Wikipedia.
int gcd(int x, int y)
{
	if(x < 1 || y < 1)
	{
		std::cerr << "Numbers are invalid for gcd. Expect only positive numbers." << std::endl;
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
