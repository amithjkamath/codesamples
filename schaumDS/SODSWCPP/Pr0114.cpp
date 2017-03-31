//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.14 on page 15
//  Tests the Babylonian Algorithm for computing square roots:

#include <iomanip.h>
#include <iostream>
using namespace std;
double f(double); 

int main()
{ for (double x=0.0; x<=2.0; x += 0.25)
  { double y = f(x);
    cout << setw(6)  << x << setw(10) << y << setw(6)  << y*y << "\n";
  }
}

double f(double x)
{ const double TOL=5e-15;
  if (x<=0) return 0.0;
  double y = (x>2?x/2:1);
  do { y = (y + x/y)/2; }
  while (x>y*y+TOL || y*y>x+TOL);
  return y;
}
