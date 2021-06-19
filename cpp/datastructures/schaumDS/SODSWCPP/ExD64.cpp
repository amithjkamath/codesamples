//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.64 page 
//  Testing the unique() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{ char* s="All is flux, nothing is stationary.";  // Heraclitus
  int l = strlen(s);
  cout << s << '\n';
  sort(s,s+l);
  cout << s << '\n';
  char* ss = unique(s,s+l);
  cout << s << '\n';
  *ss = 0;  // truncate buffer
  cout << s << '\n';
}
