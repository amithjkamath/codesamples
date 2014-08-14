#include <cstdlib>
#include <iostream>
#include <vector>

#include "game.h"
#include "board.h"
#include "player.h"
#include "die.h"

game::game()
{
	set_board(new board);

	set_number_of_players(0);

	add_player(new player("Harry"));
	add_player(new player("Sally"));

	get_player(0)->set_location(get_board()->get_starting_square());
	get_player(1)->set_location(get_board()->get_starting_square());

	my_die1.roll();
	my_die2.roll();
}

game::~game()
{

}

void game::add_player(player* inPlayer)
{
	if (inPlayer == NULL)
	{
		std::cerr << "game:add_player: player input is NULL." << std::endl;
		abort();
	}
	if (get_number_of_players() >= N)
	{	
		std::cerr << "game:add_player: index for setting is wrong." << std::endl;
		abort();
	}
	my_players->push_back (inPlayer);
	set_number_of_players(get_number_of_players() + 1);
}

void game::set_player(int index, player* inPlayer)
{
	if ((index < 0) || (index >= get_number_of_players()+1)) // is this a bug?
	{
		std::cerr << "game:set_player: index for setting is wrong." << std::endl;
		abort();
	}
	if (inPlayer == NULL)
	{
		std::cerr << "game:set_player: square input is NULL." << std::endl;
		abort();
	}
	//std::vector<player*>::iterator it;
	//it = my_players.begin();
	//it = my_players.insert (it, index);
}


player* game::get_player(int index)
{
	return my_players->at(index); //[index];
}

int game::get_number_of_players() const
{
	return number_of_players;
}

void game::set_number_of_players(int inValue)
{
	if ((inValue < 0) || (inValue >= N))
	{
		std::cerr << "board:set_number_of_players: input is wrong." << std::endl;
		abort();
	}
	number_of_players = inValue;
}

void game::play()
{
	for(int i = 0; i < 20; i++)
	{
		for(int numPlayers = 0; numPlayers < get_number_of_players();numPlayers++)
		{
			player* nowPlayer = get_player(numPlayers);
			nowPlayer->take_a_turn(get_die(1),get_die(2));
		}
	}
}

void game::set_board(board* inBoard)
{
	my_board = inBoard;
}

board* game::get_board()
{
	return my_board;
}


die game::get_die(int index)
{
	if(index == 1)
	{
		return my_die1;
	}
	if(index == 2)
	{
		return my_die2;
	}
	else
	{
		std::cerr << "game:get_die: no die!" << std::endl;
		abort();
	}
}

/*
void game::add_die(die inDie)
{
	
}
*/
