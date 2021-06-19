//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.35 on page 86
//  Evaluating a polynomial recursively

#include <iostream>

using namespace std;

double p(double* c, double x, int n);
// returns the c[0]*x^n + c[1]*x*(n-1) + ... + c[n-1]*x + c[n]

int main()
{ //double* c = new double[2];
  double c[] = { 3.0, 1.0 };
  cout << "p(c,2.0,1) = " << p(c,2.0,1) << endl;
}

double p(double* c, double x, int n)
{ if (n == 0) return c[0];     // basis
  return p(c,x,n-1)*x + c[n];  // recursion
}
