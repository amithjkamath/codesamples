//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Test driver for the Term and Polynomial classes

#include <iostream>
#include "Polynomial.h"
using namespace std;

int main()
{ // tests the Term and Polynomial classes
  Polynomial p(3.14);
  cout << "p(x) = " << p << endl;
  Term* t = new Term(-8.8,8);
  cout << "t(x) = " << *t << endl;
  p += *t;
  cout << "p(x) = " << p << endl;
  t = new Term(4.4,4);
  cout << "t(x) = " << *t << endl;
  p += *t;
  cout << "p(x) = " << p << endl;
  t = new Term(6.6,6);
  cout << "t(x) = " << *t << endl;
  p += *t;
  cout << "p(x) = " << p << endl;
  t = new Term(-3.3,3);
  cout << "t(x) = " << *t << endl;
  p += *t;
  cout << "p(x) = " << p << endl;
  t = new Term(2.2,3);
  cout << "t(x) = " << *t << endl;
  p += *t;
  cout << "p(x) = " << p << endl;
  t = new Term(1.1,3);
  cout << "t(x) = " << *t << endl;
  p += *t;
  cout << "p(x) = " << p << endl;
}
