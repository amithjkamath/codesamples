//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.8 on page 85
//  Recursive integer binary logarithm function

int lg(long n)
{ if (n == 1) return 0.0;  // basis
  return 1 + lg(n/2);      // recursion
}
