//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 1.5 on page 4
//  Simulates a simple calculator

#include <iostream>
using namespace std;

int main()
{ // performs arithmetic on integers
  int m, n;
  cout << "Enter two integers: ";  cin >> m >> n;
  char op;
  cout << "Enter an operator (+,-,*,/,%): ";  cin >> op;
  cout << "\t" << m << op << n << " = ";
  switch (op)
  { case '+': cout << m + n; break;
    case '-': cout << m - n; break;
    case '*': cout << m * n; break;
    case '/': cout << m / n; break;
    case '%': cout << m % n;
  }
}
