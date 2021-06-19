#include <iostream>
#include "square.h"

int main()
{
	// create test squares.
	square testSquare;
	square namedSquare("Hello");

	// test name.
	std::cout << "testSquare name: " << testSquare.get_name() << std::endl;
	std::cout << "namedSquare name: " << namedSquare.get_name() << std::endl;

	// change name and next square.
	testSquare.set_name("New Name");
	testSquare.set_next(&namedSquare);

	// display results.
	std::cout << "testSquare new name: " << testSquare.get_name() << std::endl;	
	std::cout << "next square name for test square: " << testSquare.get_next()->get_name() << std::endl;

	return 0;
}
