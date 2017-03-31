//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.45 page 
//  Testing the remove_if() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

class Blank
{ public:
    bool operator()(char c) { return c == ' '; }
};

int main()
{ char* s="All is flux, nothing is stationary";  // Heracleitus
  int l = strlen(s);
  int n = count(s,s+l,' ');
  cout << "l=" << l << '\n';
  cout << "n=" << n << '\n';
  remove_if(s,s+l,Blank());
  cout << s << '\n';
  s[l-n] = 0;
  cout << s << '\n';
}
