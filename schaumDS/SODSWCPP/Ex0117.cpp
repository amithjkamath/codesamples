//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.17 on page 11
//  Concatenates strings

#include <iostream>  // defines cout object
using namespace std;

int main()
{ const string s = "Pease-porridge ";
  string nurseryRhyme = s + "hot, " + s + "cold,\n";
  nurseryRhyme += s + "in the pot, nine days old.";
  cout << nurseryRhyme;
}
