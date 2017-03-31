//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Algorithm B.1 page 283
//  The Euclidean Algorithm

  long gcd(long a, long b)
  { while (b>0)
    { long r=a%b;
      a = b;
      b = r;
      // INVARIANT: gcd(a,b) is constant
    }
    return a;
  }

  long gcd(long a, long b)
  { if (b==0) return a;
    // INVARIANT: gcd(a,b) is constant
    return gcd(b,a%b);
  }