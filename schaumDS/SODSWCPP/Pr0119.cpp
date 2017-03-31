//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.19 on page 15
//  Tests the reverse digits function

#include <iostream>
using namespace std;
int reverse(int); 

int main()
{ int n;
  cout << "Enter a positive integer: ";
  cin >> n;
  cout << "reverse(n) = " << reverse(n) << "\n";
}

int reverse(int n)
{ int r=0;
  while (n>0)
  { r = 10*r + n%10;
    n /= 10;
  }
  return r;
}
