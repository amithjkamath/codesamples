//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.65 page 
//  Testing the unique_copy() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{ char* s="All is flux, nothing is stationary.";  // Heraclitus
  int l = strlen(s);
  cout << s << '\n';
  sort(s,s+l);
  cout << s << '\n';
  char buffer[80];
  char* ss = unique_copy(s,s+l,buffer);
  *ss = 0;  // truncate buffer for printing
  cout << s << '\n';
  cout << buffer << '\n';
}
