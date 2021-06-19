//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.46 page 
//  Testing the replace() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{ char* s="All is flux, nothing is stationary.";  // Heracleitus
  int l = strlen(s);
  cout << s << '\n';
  replace(s,s+l,' ','!');
  cout << s << '\n';
}
