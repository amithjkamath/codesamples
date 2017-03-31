//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.6 on page 13
//  U.S. income tax

#include <iostream>
using namespace std;

int main()
{ // prints tax due on annual income:
  const float BRACKET1 =  22100;
  const float BRACKET2 =  53500;
  const float BRACKET3 = 115000;
  const float BRACKET4 = 250000;
  const float RATE1 = 0.15;
  const float RATE2 = 0.28;
  const float RATE3 = 0.31;
  const float RATE4 = 0.36;
  const float RATE5 = 0.396;
  const float BASE2 = 3315.00;
  const float BASE3 = 12107.00;
  const float BASE4 = 31172.00;
  const float BASE5 = 79772.00;
  float income, tax;
  cout << "Enter taxable income: ";
  cin >> income;
  if      (income <= BRACKET1) tax = RATE1*income;
  else if (income <= BRACKET2) tax = BASE2 + RATE2*(income - BRACKET1);
  else if (income <= BRACKET3) tax = BASE3 + RATE3*(income - BRACKET2);
  else if (income <= BRACKET4) tax = BASE4 + RATE4*(income - BRACKET3);
  else                         tax = BASE5 + RATE5*(income - BRACKET4);
  cout << "Your tax on $" << income << " is $" << tax;
}
