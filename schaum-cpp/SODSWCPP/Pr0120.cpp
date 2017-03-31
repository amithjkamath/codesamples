//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.20 on page 15
//  Tests the reverse string function

#include <iostream>
using namespace std;
string reverse(string); 

int main()
{ string s;
  cout << "Enter a string: ";
  cin >> s;
  cout << "reverse(" << s << ") = " << reverse(s) << "\n";
}

string reverse(string s)
{ string r=s;
  int len=s.length();
  for (int i=0; i<len; i++)
    r[i] = s[len-1-i];
  return r;
}
