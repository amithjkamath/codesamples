#include <iostream>
#include "die.h"

int main()
{
	// create testDie.
	die testdie;
	
	// test initial value.
	std::cout << "initial value:" << testdie.get_face_value() << std::endl;


	// test rolling the die 20 times.
	for(int i = 1; i <= 20; i++)
	{
		std::cout << "Rolling!: " << i << "th time." << std::endl;
		testdie.roll();
		std::cout << "new value: " << testdie.get_face_value() << std::endl;
	}

	return 0;
}
