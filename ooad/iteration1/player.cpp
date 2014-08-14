#include "player.h"
#include <iostream>

player::player()
{
	set_name("");
	set_location(NULL);
}

player::player(std::string inName)
{
	set_name(inName);
	set_location(NULL);
}

player::~player()
{
	// nothing as of now.
}

std::string player::get_name() const
{
	return my_name;
}

void player::set_name(std::string inName)
{
	my_name = inName;
}

square* player::get_location() const
{
	return my_location;
}

void player::set_location(square* inSquare)
{
	my_location = inSquare;
}

void player::move(int number_of_squares)
{
	// iterate over number of movements, 
	// and set location based on next square.
	for(int i = 0; i < number_of_squares; i++)	
	{
		set_location(get_location()->get_next());
	}
}

void player::take_a_turn(die die1, die die2)
{
	// Roll the dice.
	die1.roll();
	die2.roll();

	// Display the values to move.
	int face_value_die1 = die1.get_face_value();
	int face_value_die2 = die2.get_face_value();
	int outValue = face_value_die1 + face_value_die2;
	std::cout << get_name() << " rolls " << outValue << std::endl;

	// Actually move.
	move(outValue);

	// display the new location.
	std::cout << get_name() << " is located at " << get_location()->get_name() << std::endl;

}
