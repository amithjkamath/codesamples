//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Polynomial.cpp
//  Test driver for Polynomial class

#include "Polynomial.h"

void print(string,Polynomial);

int main()
{ print("Polynomial::ZERO",Polynomial::ZERO);
  print("Polynomial::ONE",Polynomial::ONE);
  print("Polynomial::X",Polynomial::X);
  Polynomial p1;            print("p1",p1);
  p1 = Polynomial(1.0,2);   print("p1",p1);
  Polynomial p2(-1.0,2);    print("p2",p2);
  Polynomial p3 = p1 + p2;  print("p3",p3);
  p3 = Polynomial(9.0) + Polynomial(9.1,1);
  print("p3",p3);
  p3 = Polynomial(9.0) + Polynomial(9.1,1)
     + Polynomial(9.2,2) + Polynomial(9.3,3)
     + Polynomial(9.2,4) + Polynomial(9.5,5);
  print("p3",p3);
  print("-2*p3",-2*p3);
  print("p3-p3",p3-p3);
  Polynomial p4 = Polynomial(2,3) - Polynomial(2,1);
  print("p4",p4);
  print("p3*p4",p3*p4);
/*
  p3 = Polynomial(5.0) + Polynomial(3,1) + Polynomial(1,6);
  print("p3",p3);
  p3 = 7*Polynomial::X - 3*Polynomial::ONE;
  print("p3",p3);
  p3 *= p3;
  print("p3",p3);
  p4 = Polynomial(2,7) + Polynomial(-8,3)
     + Polynomial(5,2) + Polynomial(9,0);
  print("p4",p4);
*/
}

void print(string name, Polynomial p)
{ cout << name << "(x) = " << p;
  cout << "\tdegree=" << p.degree() << ", terms=" << p.terms()
       << ", " << name << "(2.0)=" << p(2.0) << '\n';
}
