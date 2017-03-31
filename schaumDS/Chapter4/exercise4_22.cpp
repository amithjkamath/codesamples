#include <iostream>
#include <string>
int main(void)
{
int grade = 0;
std::string finalGrade;

std::cout << "Enter marks out of 100: " << std::endl;
std::cin >> grade;

//Using conditional operators.
//finalGrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : (grade < 75) ? "low pass" : "pass";

//Using if-else, definitely easier to read.
if(grade > 90)
	finalGrade = "high pass";
	else if(grade > 75)
		finalGrade = "pass";
		else if(grade > 60)
			finalGrade = "low pass";
			else
			finalGrade = "fail";
			
std::cout << "The final grade is: " << finalGrade << std::endl;
return 0;
}