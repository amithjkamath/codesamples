//definitions.cpp
#include <iostream>
#include "get.h"
#include <string>

int main(void)
{
	bool myBool(false);
	char myChar('a');
	int myInt(0);
	double myDouble(0.0);
	std::string myString("");
	
	myBool = get_bool("Input a boolean:");
	std::cout << "The boolean myBool is " << myBool << std::endl;
	
	myChar = get_char("Input a character:");
	std::cout << "The character myChar is " << myChar << std::endl;

	myInt = get_int("Input an integer:");
	std::cout << "The integer myBool is " << myInt << std::endl;

	myDouble = get_double("Input a double:");
	std::cout << "The double myDouble is " << myDouble << std::endl;

	myString = get_string(std::cin,"Input a string:");
	std::cout << "The string myString is " << myString << std::endl;	
	return 0;
}