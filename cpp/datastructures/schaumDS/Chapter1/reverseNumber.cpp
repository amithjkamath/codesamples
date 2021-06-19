// reverseNumber.cpp
// This is exercise  1.19 in Schaum book.

#include <iostream>
#include <cmath>

int reverse(int inNumber);

int main(void)
{
	int number = 4205;
	std::cout << "Original Number is: " << number << std::endl;
	int revNumber = reverse(number);
	std::cout << "Reversed Number is: " << revNumber << std::endl;	
	number = 12344205;
	std::cout << "Original Number is: " << number << std::endl;
	revNumber = reverse(number);
	std::cout << "Reversed Number is: " << revNumber << std::endl;	
	number = 42050987;
	std::cout << "Original Number is: " << number << std::endl;
	revNumber = reverse(number);
	std::cout << "Reversed Number is: " << revNumber << std::endl;		
	return 0;
}

int reverse(int inNumber)
{
	int result = 0;
	while(inNumber > 0)
	{
		result = result*10 + (inNumber%10);	
		inNumber = inNumber - inNumber%10;
		inNumber = inNumber/10;
	}
	return result;
}