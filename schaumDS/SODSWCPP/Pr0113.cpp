//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.13 on page 15
//  Computes the exponential function e^x:

#include <iomanip.h>
#include <iostream>
using namespace std;

int main()
{ const double TOL=5e-15;  // maximal round-off error
  double x;
  cout << "Enter x: ";
  cin >> x;
  double t=1, y=1;
  int n=0;
  while(t>TOL || -t>TOL)
  { t *= x/++n;
    y += t;
    cout << setw(16) << n << ":"
         << setprecision(15) << setw(20) << y << "\n";
  }
}
