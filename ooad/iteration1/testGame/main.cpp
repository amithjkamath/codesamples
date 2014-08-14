#include "game.h"

int main(int argc, char * argv[])
{
	game g;

	//add players from the command line arguments.
	for (int i = 1; i < argc; ++i)
	{
		g.add_player(new player(argv[i]));
	}

	// play game.
	g.play();
	
	return 0;
}
