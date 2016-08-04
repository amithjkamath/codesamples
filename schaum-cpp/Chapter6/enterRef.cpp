//enterRef.cpp
// build as g++ -o enterRef enterRef.cpp ../get.cpp
#include <iostream>
#include <string>
#include "../get.h"

void enter(const std::string& prompt, std::string& changed);

int main(void)
{
	std::string address("");
	enter("Address?",address);
	std::cout << "address is " << address << std::endl;
	
	return 0;
}

void enter(const std::string& prompt, std::string& changed)
{
	 changed = get_string(prompt);
}