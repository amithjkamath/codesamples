//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.47 page 
//  Testing the replace_copy() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{ char* s="All is flux, nothing is stationary.";  // Heracleitus
  cout << s << '\n';
  int l = strlen(s);
  char buffer[80];
  char* ss = replace_copy(s,s+l,buffer,'n','N');
  *ss = 0;  // truncate buffer for printing
  cout << s << '\n';
  cout << buffer << '\n';
}
