//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 4.8 on page 80
//  Recursive implementation of the greatest common divisor function

long gcd(long m, long n)
{ if (m == n) return n;               // basis
  else if (m < n) return gcd(m,n-m);  // recursion
  else return gcd(m-n,n);             // recursion
}
