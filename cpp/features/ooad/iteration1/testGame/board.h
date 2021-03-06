#ifndef BOARD_HEADER 
#define BOARD_HEADER

class square; // forward class declaration: works here because 
// we are only dealing with square* and not the actual object.

class board
{
	public:
		board();
		~board();

		square* get_starting_square() const;

	private:
		static const int N = 40;

	private: // methods
		square* get_square(int index) const;
		void add_square(square* inSquare);
		void set_square(int index, square* inSquare);

		int get_number_of_squares() const;
		void set_number_of_squares(int inValue);

	private: // data members.
		int number_of_squares;
		square* my_squares[N];
		square* my_starting_square;
};
#endif
