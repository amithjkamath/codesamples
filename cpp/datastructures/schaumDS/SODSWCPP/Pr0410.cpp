//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 4.10 on page 85
//  Recursive function that echos an input string in reverse

void reverse()
{ char c;
  cin.get(c);
  if (c == '\n') return;  // basis
  reverse();              // recursion
  cout << c;
}
