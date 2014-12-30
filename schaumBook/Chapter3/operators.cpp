//definitions.cpp
// build as 'g++ -o operators operators.cpp ../get.cpp'
#include <iostream>
#include "../get.h" // note that this uses the get.h in the parent directory.
#include <string>

int main(void)
{
	double balance = get_double("Enter the current balance: ");
	double interest = get_double("Enter the interest rate in %: ");
	int time = get_int("Enter time in months: ");
	
	std::cout << "The balance after " << time << " months is " << balance*time*interest/100 << std::endl;
	return 0;
}