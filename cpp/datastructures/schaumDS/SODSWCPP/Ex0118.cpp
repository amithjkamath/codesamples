//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 1.18 on page 11
//  Searches for substrings

#include <iostream>  // defines cout object
#include <limits>  // defines cout object
using namespace std;

int main()
{ const string str = "Mississippi";
  const string substr = "issi";
  cout << "str.find(substr) = " << str.find(substr) << "\n";
  cout << "str.find(substr,2) = " << str.find(substr,2) << "\n";
  cout << "str.find(substr,8) = " << str.find(substr,8) << "\n";
  cout << "          UINT_MAX = " << UINT_MAX << "\n";
}
