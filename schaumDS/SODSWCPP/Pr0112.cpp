//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.12 on page 15
//  Tests the factorial() function

#include <iostream>
using namespace std;
int factorial(int); 

int main()
{ for (int n=0; n<12; n++)
    cout << n << "\t" << factorial(n) << "\n";
}

int factorial(int n)
{ int f=1;
  for (int i=2; i<=n; i++)
    f *= i;
  return f;
}
