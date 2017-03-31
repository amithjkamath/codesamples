//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 4.1 on page 76
//  Recursive implementation of the factorial function

long f(int n)
{ if (n < 2) return 1;  // basis
  return n*f(n-1);      // recursion
}
