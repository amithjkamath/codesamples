//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Ratio.cpp
//  Test driver for the Ratio class

#include "Ratio.h"
void print(long,long);

int main()
{ print(44,12);
  print(3,-8);
  Ratio r1(44,12);
  cout << "r1 = 44/12 = " << r1 << "\n";
  Ratio r2(22,7);
  cout << "r2 = 22/7 = " << r2 << "\n";
  cout << "r1+r2 = " << r1+r2 << "\n";
  cout << "r1-r2 = " << r1-r2 << "\n";
  cout << "r1*r2 = " << r1*r2 << "\n";
  cout << "r1/r2 = " << r1/r2 << "\n";
  r2.invert();
  cout << "r2 inverted = " << r2 << "\n";
  Ratio r0(100,0);
  cout << "r0 = 100/0 = " << r0 << "\n";
  r0 = Ratio(0,5);
  cout << "r0 = 0/5 = " << r0 << "\n";
}

void print(long n, long d)
{ Ratio r(n,d);
  cout << n << "/" << d << " = " << r << "\n";
  cout << "\tr.numerator() = " << r.numerator() << "\n";
  cout << "\tr.denominator() = " << r.denominator() << "\n";
  cout << "\tr.reciprocal() = " << r.reciprocal() << "\n";
  cout << "\tdouble(r) = " << double(r) << "\n";
}
