//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.20 on page 85
//  Iterative implementation of the Euclidean algorithm

long gcd(long m, long n)
{ while (n > 0)
  { long r = m%n;
      m = n;
      n = r;  // INVARIANT: gcd(m,n)
    }
    return m;
}
