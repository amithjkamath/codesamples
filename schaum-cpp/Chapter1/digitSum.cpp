// digitSum.cpp
// This is exercise  1.18 in Schaum book.

#include <iostream>

int digitSum(int inNumber);

int main(void)
{
	int number = 4205;
	std::cout << "Original Number is: " << number << std::endl;
	int adddigits = digitSum(number);
	std::cout << "Sum of Digits is: " << adddigits << std::endl;	
	number = 12344205;
	std::cout << "Original Number is: " << number << std::endl;
	adddigits = digitSum(number);
	std::cout << "Sum of Digits is: " << adddigits << std::endl;	
	number = 42050987;
	std::cout << "Original Number is: " << number << std::endl;
	adddigits = digitSum(number);
	std::cout << "Sum of Digits is: " << adddigits << std::endl;		
	return 0;
}

int digitSum(int inNumber)
{
	int result = 0;
	while(inNumber > 0)
	{
		result += inNumber%10;	
		inNumber = inNumber - inNumber%10;
		inNumber = inNumber/10;
	}
	return result;
}