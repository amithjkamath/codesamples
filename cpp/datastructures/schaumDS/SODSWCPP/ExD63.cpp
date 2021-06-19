//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.63 page 
//  Testing the transform() algorithm

#include <algorithm>
#include <ctype.h>
#include <iostream>
using namespace std;

char capital(char);

int main()
{ char* s="All is flux, nothing is stationary.";  // Heraclitus
  int l = strlen(s);
  char buffer[80];
  char* ss = transform(s,s+l,buffer,capital);
  *ss = 0;  // truncate buffer
  cout << s << '\n';
  cout << buffer << '\n';
}

char capital(char c)
{ return (isalpha(c) ? toupper(c) : c);
}
