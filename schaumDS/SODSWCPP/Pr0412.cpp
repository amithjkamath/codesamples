//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.12 on page 85
//  Recursive function that converts decimal to hexadecimal

string hex(int);

string hexadecimal(long n)
{ string s = hex(n%16);
  if (n < 16) return s;          // basis
  return hexadecimal(n/16) + s;  // recursion
}

string hex(int n)
{ if (n == 0)  return "0";
  if (n == 1)  return "1";
  if (n == 2)  return "2";
  if (n == 3)  return "3";
  if (n == 4)  return "4";
  if (n == 5)  return "5";
  if (n == 6)  return "6";
  if (n == 7)  return "7";
  if (n == 8)  return "8";
  if (n == 9)  return "9";
  if (n == 10) return "A";
  if (n == 11) return "B";
  if (n == 12) return "C";
  if (n == 13) return "D";
  if (n == 14) return "E";
  else         return "F";
}
