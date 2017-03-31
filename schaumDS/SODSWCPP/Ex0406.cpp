//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 4.6 on page 89
//  Recursive implementation of the binomial coefficients

long c(int n, int k)
{ if (k == 0 or k == n) return 1;  // basis
  return c(n-1,k-1) + c(n-1,k);    // recursion
}
