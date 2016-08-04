// main.cpp

#include <cstdlib>
#include <ctime>
#include <vector>
#include "game.h"
#include "player.h"

int main(int argc, char * argv[])
{
	// seed the random number generator:
	srand((unsigned) time(NULL));
	
	std::vector<player *> the_players;
	
	game g;
	
	for (int i = 1; i < argc; ++i)
	{
		player * a_player = new player(argv[i]);
		g.add_player(*a_player);
		the_players.push_back(a_player);
	}
	
	g.play();
	
	std::vector<player *>::iterator start(the_players.begin());
	std::vector<player *>::iterator stop (the_players.end()  );
	while (start != stop)
	{
		delete *start;
		
		++start;
	}
	
	return 0;
}
