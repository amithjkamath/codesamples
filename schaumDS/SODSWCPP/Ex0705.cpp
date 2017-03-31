//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 7.5 on page 134
//  Test driver for a Polynomial class

#include "Polynomial.h"
void print(string,Polynomial);

int main()
{ Polynomial p1;            print("p1",p1);  // p1(x) = 0
  p1 = Polynomial(1.0,2);   print("p1",p1);  // p1(x) = x^2
  p1 = 10*p1;               print("p1",p1);  // p1(x) = 10x^2
  Polynomial p2(-1.0,2);    print("p2",p2);  // p2(x) = -x^2
  Polynomial p3 = p1 + p2;  print("p3",p3);  // p3(x) = 9x^2
  p3 = p1 + 10*p2;          print("p3",p3);  // p3(x) = 0
  Polynomial p4(4.0,7);     print("p4",p4);  // p4(x) = 4x^7
  p3 = p2 + p4;             print("p3",p3);  // p3(x) = 4x^7 - x^2
  p2 = Polynomial::ZERO;    print("p2",p2);  // p2(x) = 0
}

void print(string name, Polynomial p)
{ cout << name << "(x) = " << p;
  cout << "\tdegree=" << p.degree() << ", terms=" << p.terms()
       << ", " << name << "(2.0)=" << p(2.0) << '\n';
}
