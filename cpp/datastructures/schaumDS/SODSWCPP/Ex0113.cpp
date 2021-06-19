//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 1.13 on page 9
//  Testing a power() function

#include <iostream>
using namespace std;
double power(const double, const int);

int main()
{ cout << "power(2,0) = " << power(2,0) << "\n";
  cout << "power(2,1) = " << power(2,1) << "\n";
  cout << "power(2,2) = " << power(2,2) << "\n";
  cout << "power(2,3) = " << power(2,3) << "\n";
  cout << "power(2,-3) = " << power(2,-3) << "\n";
  cout << "power(2.01,3) = " << power(2.01,3) << "\n";
}

double power(const double x, const int n)
{ double y=1.0;
  for (int i=0; i<n; i++)  // if n>0, y = x*x*...*x (n times)
    y *= x;
  for (int i=0; i>n; i--)  // if n<0, y = 1/x*x*...*x (n times)
    y /= x;
  return y;
}
