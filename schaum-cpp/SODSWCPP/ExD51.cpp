//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.51 page 
//  Testing the reverse_copy() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{ char* s="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  cout << s << '\n';
  char buffer[80];
  char* ss = reverse_copy(s,s+26,buffer);
  *ss = 0;  // truncate buffer for printing
  cout << s << '\n';
  cout << buffer << '\n';
}
