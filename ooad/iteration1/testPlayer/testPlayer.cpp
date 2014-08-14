#include <iostream>
#include "player.h"
#include "die.h"
#include "square.h"

int main()
{
	player testplayer;

	square testSquare;

	die testDie1;
	die testDie2;

	testSquare.set_name("First Square");

	testplayer.set_location(&testSquare);
	std::cout << "testPlayer is at " << testplayer.get_location()->get_name() << std::endl;
	return 0;
}
