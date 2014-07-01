#include <iostream>
#include "derivedMatrix.h"

int main()
{
	derivedMatrix m(1,1, 1.5);
	m.setVal(2.5,1,1);
	m.display();
	std::cout << "determinant is now " << m.getDeterminant() << std::endl;

	return 0;
}
