#include <iostream>

#include "testRef.h"

int main()
{
	testRef thisRef;
	thisRef.setName("MyName");

	std::cout << "thisRef has name " << thisRef.getName() << std::endl;

	testRef otherRef = thisRef;

	std::cout << "otherRef has name " << otherRef.getName() << std::endl;
	
	otherRef.setName("newName");

	thisRef = otherRef;

	std::cout << "thisRef has name " << thisRef.getName() << std::endl;

	testRef newRef;

	std::cout << "newRef has name " << newRef.getName() << std::endl;	

	return 0;
}
