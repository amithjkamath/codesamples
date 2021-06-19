// reverseString.cpp
// this is exercise 1.20 in the Schaum book.
#include <iostream>
#include <string>

std::string reverseString(std::string inputString);
bool isPalindrome(std::string inStr);
 
int main(void)
{
	std::cout << "Enter a string:" << std::endl;
	std::string inputString;
	std::cin >> inputString;
	std::cout << "This is what you entered: " << inputString << std::endl;
	std::cout << "This is the reverse: " << reverseString(inputString) << std::endl;
	std::cout << "This is what you entered: " << inputString << std::endl;	
	std::cout << "Is this a palindrome: " << isPalindrome(inputString) << std::endl;
	return 0;
}

std::string reverseString(std::string inputString)
{
	char temp = 0;
	int len = inputString.length();
	std::cout << len << std::endl;
	for(int i = 0; i < len/2; i++)
	{
		std::cout << inputString[i] << std::endl;
		temp = inputString[i];
		inputString[i] = inputString[len - 1 - i];
		inputString[len - 1 - i] = temp;
	}
	return inputString;
}

bool isPalindrome(std::string inputString)
{
	std::string revString = reverseString(inputString);
	int len = inputString.length();
	for(int i = 0; i < len; i++)
	{
		if(inputString[i] != revString[i])
			return false;
	}
	return true;
}