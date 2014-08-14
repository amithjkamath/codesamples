#ifndef GAME_HEADER 
#define GAME_HEADER

#include <vector>

#include "board.h"
#include "die.h"
#include "player.h"

class game
{
	public:
		game();
		~game();

		void play();

	private: // member functions.
		void set_board(board* inBoard);
		board* get_board();

		void add_player(player* inPlayer);
		void set_player(int index, player* inPlayer);
		player* get_player(int index);

		int get_number_of_players() const;
		void set_number_of_players(int inValue);

		die get_die(int index);
		//void add_die(die inDie);

	private: // data members.
		static const int N = 9;
		board* my_board;
		std::vector<player*> my_players[N];
		int number_of_players;
		die my_die1;
		die my_die2;
};
#endif
