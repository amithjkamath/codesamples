#ifndef SQUARE_HEADER 
#define SQUARE_HEADER

#include <string> // for std::string

class square
{
	public:
		 square();
		 square(std::string name);
		~square();

		void        set_next(square* inSquare);
		square*     get_next() const;
		void        set_name(std::string inName);
		std::string get_name() const;

	private:
		std::string my_name;
		square*     my_next;
};
#endif
