//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.18 on page 85
//  Iterative implementation of the Euclidean algorithm

long gcd(long m, long n)
{ while (m != n)  // INVARIANT: gcd(m,n)
    if (m < n) n -= m;
    else m -= n;
  return n;
}
