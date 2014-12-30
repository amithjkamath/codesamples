#include "person.h"
#include "car.h"
#include <iostream>
#include <string>

person::person()
{
	setName("");
	myCar = new car;
}

person::person(const std::string& inName, car& inCar)
{
	setName(inName);
	setCar(inCar);
}


person::person(const person& other)
{	
	setCar(other.getCar());
	setName(other.getName());
}

person& person::operator=(const person& other)
{
	setCar(other.getCar());
	setName(other.getName());
	return *this;	
}

const car& person::getCar() const
{
	return *myCar;
}

const std::string& person::getName() const
{
	return myName;
}

void person::show()
{
	std::cout << "My name is " << myName
	<< " and my car is ";
	myCar->show();
	std::cout << std::endl;
}

void person::setName(const std::string& inName)
{
	myName = std::string(inName);
}

void person::setCar(const car& inCar)
{
	myCar = new car(inCar);
}

person::~person()
{
	//delete myCar;
	//delete myName;
}
