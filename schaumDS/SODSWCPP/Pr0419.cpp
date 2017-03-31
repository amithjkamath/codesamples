//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.19 on page 85
//  Recursive implementation of the Euclidean algorithm

long gcd(long m, long n)
{ if (m == 0) return n;               // basis
  if (n == 0) return m;               // basis
  else if (m < n) return gcd(m,n%m);  // recursion
  else return gcd(m%n,n);             // recursion
}
