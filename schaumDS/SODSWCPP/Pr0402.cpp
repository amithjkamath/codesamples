//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.2 on page 85
//  Recursive sum of powers function
//  Implements Horner's method

double sum(double b, int n)
{ if (n == 0) return 1;     // basis
  return 1 + b*sum(b,n-1);  // recursion
}
