//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 1.14 on page 10
//  Testing the string class

#include <iostream>
using namespace std;

int main()
{ string s="ABCDEFGH";
  cout << "s = [" << s << "]\n";
  cout << "s.length() = " << s.length() << "\n";
  cout << "s.substr(2,4) = [" << s.substr(2,4) << "]\n";
}
