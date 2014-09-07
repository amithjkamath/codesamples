#include <iostream>
#include <string>

#include "base.h"

base::base()
{
	_name = "base";
}


base::base(std::string inName)
{
	_name = inName;
}

void base::print()
{
	std::cout << _name << std::endl;
}
