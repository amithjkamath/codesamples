//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 4.2 on page 76
//  Iterative implementation of the factorial function

long f(int n)
{ long f=1;
  for (int i=2; i<=n; i++)
    f *= i;
  return f;
}
