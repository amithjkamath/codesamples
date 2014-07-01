#include "point.h"

#include <iostream>
#include <cstdlib>

point::point()
{
	setX(0);
	setY(0);
}

point::point(int inX, int inY)
{
	setX(inX);
	setY(inY);
}

point::point(const point& other) // copy constructor.
{
	std::cout << "Using copy constructor." << std::endl;
	setX(other.getX());
	setY(other.getY());
}

point& point::operator=(const point& other) // assignment operator.
{
	std::cout << "Using assignment operator." << std::endl;
	setX(other.getX());
	setY(other.getY());
	return *this;
}
		
void point::setX(double x)
{
	if(x >= 0)
		_x = x;
	else
	{
		std::cerr << "error: negative x not allowed" << std::endl;
		exit(1);
	}
}

void point::setY(double y)
{
	if(y >= 0)
		_y = y;
	else
	{
		std::cerr << "error: negative y not allowed" << std::endl;
		exit(1);
	}
}
		
double point::getX() const
{
	return _x;
}

double point::getY() const
{
	return _y;
}

void point::show()
{
	std::cout << "X: " << getX() << " Y: " << getY() << std::endl;
}

point::~point()
{
	//do nothing. No variables on heap.
}
