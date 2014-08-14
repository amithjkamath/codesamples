#include <iostream>
#include "player.h"
#include "square.h"

int main()
{
	//create player.
	player testplayer;
	//create square.
	square testSquare;

	// set properties.
	testSquare.set_name("First Square");
	testplayer.set_location(&testSquare);
	std::cout << "testPlayer is at " << testplayer.get_location()->get_name() << std::endl;
	return 0;
}
