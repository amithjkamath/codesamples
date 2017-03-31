//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.14 on page 85
//  Recursive Ackermann function

int ackermann(int m, int n)
{ if (m == 0) return 1;                     // basis
  if (n == 0)
    if (m == 1) return 2;                   // basis
    else return m + 2;                      // basis
  return ackermann(ackermann(m-1,n), n-1);  // recursion
}