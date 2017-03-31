//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 4.7 on page 79
//  Iterative implementation of the binomial coefficients function

long c(int n, int k)
{ long c = 1;
  for (int j=1; j <= k; j++)
    c = c*(n-j+1)/j;
  return c;
}
