//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.15 on page 85
//  Iterative implementation of the Fibonacci function

long fib(int n)
{ if (n < 2) return n;
  long f0=0, f1=1, f=f0+f1;
  for (int i=2; i<n; i++)
  { f0 = f1;
    f1 = f;
    f = f0 + f1;
  }
  return f;
}
