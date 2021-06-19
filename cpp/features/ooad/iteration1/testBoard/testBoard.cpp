#include <iostream>
#include "board.h"
#include "square.h"

int main()
{
	board testboard;

	square* thisSquare = testboard.get_starting_square();
	std::cout << "Starting square is: " << thisSquare->get_name() << std::endl;
	return 0;
}
