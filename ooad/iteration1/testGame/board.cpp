#include "board.h"

#include <iostream>	// for std::cout et al.
#include <cstdlib> // for abort.
#include "square.h"

#define DEBUG 0

board::board()
{
	set_number_of_squares(0);

	add_square(new square("Go"));
	add_square(new square("Mediterranean Avenue"));
	add_square(new square("Community Chest"));
	add_square(new square("Baltic Avenue"));
	add_square(new square("Income Tax"));
	add_square(new square("Reading Railroad"));
	add_square(new square("Oriental Avenue"));
	add_square(new square("Chance"));
	add_square(new square("Vermont Avenue"));
	add_square(new square("Connecticut Avenue"));
	add_square(new square("Just Visiting"));
	add_square(new square("St. Charles Place"));
	add_square(new square("Electric Company"));
	add_square(new square("States Avenue"));
	add_square(new square("Virginia Avenue"));
	add_square(new square("Pennsylvania Railroad"));
	add_square(new square("St. James Place"));
	add_square(new square("Community Chest"));
	add_square(new square("Tennessee Avenue"));
	add_square(new square("New York Avenue"));
	add_square(new square("Free Parking"));
	add_square(new square("Kentucky Avenue"));
	add_square(new square("Chance"));
	add_square(new square("Indiana Avenue"));
	add_square(new square("Illinois Avenue"));
	add_square(new square("B & O Railroad"));
	add_square(new square("Atlantic Avenue"));
	add_square(new square("Ventnor Avenue"));
	add_square(new square("Water Works"));
	add_square(new square("Marvin Gardens"));
	add_square(new square("Go To Jail"));
	add_square(new square("Pacific Avenue"));
	add_square(new square("North Carolina Avenue"));
	add_square(new square("Community Chest"));
	add_square(new square("Pennsylvania Avenue"));
	add_square(new square("Short Line Railroad"));
	add_square(new square("Chance"));
	add_square(new square("Park Place"));
	add_square(new square("Luxury Tax"));
	add_square(new square("Boardwalk"));

	// add the link to the next square.
	for(int i = 0; i < 39; i++)
	{
		get_square(i)->set_next(get_square(i+1));
	}
	get_square(39)->set_next(get_square(0));

	// setup starting square to be the Go square.
	my_starting_square = get_square(0);
}

board::~board()
{
	//free(my_squares);
}

int board::get_number_of_squares() const
{
	return number_of_squares;
}

void board::set_number_of_squares(int inValue)
{
	if ((inValue < 0) || (inValue > N))
	{
		std::cerr << "board:set_number_of_squares: input is wrong." << std::endl;
		abort();
	}
	number_of_squares = inValue;
}

square* board::get_starting_square() const
{
	return my_starting_square;
}

square* board::get_square(int index) const
{
	if ((index < 0) || (index > get_number_of_squares()))
	{
		std::cerr << "board:get_square: index is wrong." << std::endl;
		abort();
	}
	return my_squares[index];
}

void board::set_square(int index, square* inSquare)
{
	if ((index < 0) || (index > get_number_of_squares()))
	{	
		std::cerr << "board:set_square: index for setting is wrong." << std::endl;
		abort();
	}
	if (inSquare == NULL)
	{
		std::cerr << "board:set_square: square input is NULL." << std::endl;
		abort();
	}
	my_squares[index] = inSquare;

#if DEBUG
	std::cout << "Set Square: " << inSquare->get_name() << std::endl;
#endif

}

void board::add_square(square* inSquare)
{
	if (inSquare == NULL)
	{
		std::cerr << "board:add_square: square input is NULL." << std::endl;
		abort();
	}
	if (get_number_of_squares() > N)
	{	
		std::cerr << "board:add_square: index for setting is wrong." << std::endl;
		abort();
	}
	set_square(get_number_of_squares(), inSquare);

#if DEBUG
	std::cout << "Added Square: " << inSquare->get_name() << std::endl;
#endif

	set_number_of_squares(get_number_of_squares() + 1);
}
