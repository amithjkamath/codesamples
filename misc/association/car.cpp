#include "car.h" //eat your own cooking.

#include <iostream>
#include <string>

car::car()
: year(0), insured(false)
{
	setName("");
}

car::car(int y, bool ins, const std::string& inName)
: insured(ins)
{
	setYear(y);
	setName(inName);
}

int car::getYear()
{
	return year;
}

bool car::isInsured()
{
	return insured;
}

const std::string& car::getName() const
{
	return *name;
}

void car::setName(const std::string& inName)
{
	name = new std::string(inName);
}

void car::show()
{
	std::cout << *name 
	<< " Year: " << year
	<< " (" << insured << ") "
	<< std ::endl;
}

car::~car()
{
	delete name;
}

void car::setYear(int y)
{
	if(y > 1900)
	{
		year = y;
	}
}

void car::setInsured(bool ins)
{
	insured = ins;
}
