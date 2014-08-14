#include "square.h"
		
square::square()
{
	set_name("");
	set_next(NULL);
}

square::square(std::string name)
{
	set_name(name);
	set_next(NULL);
}

square::~square()
{
	//nothing here really.
}

void square::set_next(square* inSquare)
{
	my_next = inSquare;
}

square* square::get_next() const
{
	return my_next;
}

void square::set_name(std::string inName)
{
	my_name = inName;
}


std::string square::get_name() const
{
	return my_name;
}
