//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.43 page 
//  Testing the remove_copy() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{ char* s="All is flux, nothing is stationary";  // Heracleitus
  char buffer[80];
  int l = strlen(s);
  int n = count(s,s+l,' ');
  cout << "l=" << l << '\n';
  cout << "n=" << n << '\n';
  char* ss = remove_copy(s,s+l,buffer,' ');
  *ss = 0;  // truncate buffer
  cout << s << '\n';
  cout << buffer << '\n';
  cout << ss-buffer << '\n';
}
