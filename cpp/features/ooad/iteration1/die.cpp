#include "die.h"

#include <iostream> // for the std::cout
#include <cstdlib> //for rand and error.
#include <ctime> // for the time to seed the random number.

die::die()
{
	srand(time(NULL));
	roll();
}


die::~die()
{
	// nothing here for now.
}

int die::get_face_value()
{
	return my_face_value;
}

void die::roll()
{
	set_face_value(rand() % 6 + 1);
}

void die::set_face_value(int inFaceValue)
{
	if((inFaceValue < 1) || (inFaceValue > 6))
	{
		std::cerr << "die:set_face_value: invalid input." << std::endl;
		abort();
	}
	else
		my_face_value = inFaceValue;
}
