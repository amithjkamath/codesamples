//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.49 page 
//  Testing the replace_if() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

class Blank
{ public:
    bool operator()(char c) { return c == ' '; }
};

int main()
{ char* s="All is flux, nothing is stationary.";  // Heracleitus
  int l = strlen(s);
  cout << s << '\n';
  replace_if(s,s+l,Blank(),'!');
  cout << s << '\n';
}
