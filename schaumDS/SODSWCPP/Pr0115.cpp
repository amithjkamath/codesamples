//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.15 on page 15
//  Tests the integral binary logarithm function

#include <iostream>
using namespace std;
int lg(double); 

int main()
{ cout << "lg(1) = " << lg(1) << "\n";
  cout << "lg(2) = " << lg(2) << "\n";
  cout << "lg(3) = " << lg(3) << "\n";
  cout << "lg(4) = " << lg(4) << "\n";
  cout << "lg(5) = " << lg(5) << "\n";
  cout << "lg(100) = " << lg(100) << "\n";
  cout << "lg(1000) = " << lg(1000) << "\n";
  cout << "lg(100000) = " << lg(1000000) << "\n";
}

int lg(double x)
{ int y=0;
  while (x>1)
  { x /= 2;
    ++y;
  }
  return y;
}
