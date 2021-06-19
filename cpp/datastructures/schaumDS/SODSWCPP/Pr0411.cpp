//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.11 on page 85
//  Recursive function that converts decimal to binary

string binary(long n)
{ string s;
  if (n%2 == 0) s = "0";
  else s = "1";
  if (n < 2) return s;     // basis
  return binary(n/2) + s;  // recursion
}
