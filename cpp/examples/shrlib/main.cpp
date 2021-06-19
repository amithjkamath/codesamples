#include <iostream>
#include "libcode.h"

int main(void)
{
	std::cout << "5 + 6 = " << add(5, 6) << std::endl;
	std::cout << "3 - 4 = " << minus(3, 4) << std::endl;
	std::cout << "4 * 5 = " << product(4, 5) << std::endl;
	return 0;
}
