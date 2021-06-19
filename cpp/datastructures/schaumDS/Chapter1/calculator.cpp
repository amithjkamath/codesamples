//calculator.cpp
//Problem 1.3 from schaum
// build as g++ -o calculator calculator.cpp 
#include <iostream>

int main(void)
{
	//performs arithmetic on two integers.
	double m, n;
	std::cout << "Enter two integers: "; std::cin >> m >> n;
	char op;
	std::cout << "Enter an operator (+, -, *, /): "; std::cin >> op;
	std::cout << "\t" << m << op << n << " = ";
	switch(op)
	{
		case '+': std::cout << m + n; break;
		case '-': std::cout << m - n; break;
		case '*': std::cout << m * n; break;
		case '/': if(n != 0) std::cout << m / n; else std::cout << "undefined"; break;		
	}
	std::cout << std::endl;
	return 0;
}