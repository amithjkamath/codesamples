//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 4.4 on page 77
//  Recursive implementation of the Fibonacci function

long fib(int n)
{ if (n < 2) return n;         //  basis
  return fib(n-1) + fib(n-2);  // recursion
}
