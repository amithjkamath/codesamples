//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.1 on page 85
//  Recursive sum of squares function

long sum(int n)
{ if (n == 0) return 0;   // basis
  return sum(n-1) + n*n;  // recursion
}
