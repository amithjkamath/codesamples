#include <iostream> // for std::cerr
#include <cstdlib> // for exit
#include "fraction.h"

	//constructors
	fraction::fraction()
	{
		setNum(0);
		setDen(1); //agree that this is the default.
	}
	
	fraction::fraction(int numVal, int denval)
	{
		setNum(numVal);
		setDen(denval);
	}

	// functions
	bool fraction::isZero()
	{
		return (getNum() == 0);
	}
	
	bool fraction::isNegative()
	{
		return (((getNum() < 0) && (getDen() > 0)) || ((getNum() > 0) && (getDen() < 0)));
	}

	//getters and setters
	void fraction::setNum(int val)
	{
		myNum = val;
	}
	
	int fraction::getNum()
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
		}
	}
	
	int fraction::getDen()
	{
		return myDen;
	}
	
	void fraction::display()
	{
		std::cout << "Fraction is: " << getNum() << "/" << getDen() << std::endl;
	}
	
	//Overloaded operators
	fraction& fraction::operator+(fraction& other)
	{
		setNum(getNum() + other.getNum());
		setDen(getDen() + other.getDen());
		return *this;
	}
	
	bool fraction::operator==(fraction& other)
	{
		return (((double)myNum/(double)myDen) == ((double)other.myNum/(double)other.myDen));
	}
