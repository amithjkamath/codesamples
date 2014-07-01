#include "creature.h"

#include <iostream>
#include <string>

creature::creature()
: myLocation(0,0), myName("")
{
	//using initializer lists, because the objects need to be defined as soon as this class is.
	// to avoid errors if any contain const properties, which need to be defined at creation.
}

creature::creature(std::string inName, point inLoc)
: myName(inName)
{
	myLocation.setX(inLoc.getX());
	myLocation.setY(inLoc.getY());
}

/*
creature::creature(const creature& other)
{
	// the following lines are shallow copy.	
	myLocation = other.getLocation;
	myName = other.getName;
}

creature& creature::operator=(const creature& other)
{
	// the following lines are shallow copy.	
	this->myLocation = other.getLocation;
	this->myName = other.getName;
	return *this;
}
*/
		
void creature::setName(const std::string& inName)
{
	myName = inName;
}

void creature::setLocation(const point loc)
{
	myLocation = loc;
}

point creature::getLocation() const
{
	return myLocation;
}

std::string creature::getName() const
{
	return myName;
}

void creature::show()
{
	std::cout << "My name is " << myName << std::endl;
	std::cout << "My location is " << std::endl;
	myLocation.show();
}

creature::~creature()
{
	//delete myLocation;
	//delete myName;
}

