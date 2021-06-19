//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.60 page 
//  Testing the sort() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{ char* p="GAJBHCHDIEFAGDHC";
  cout << p << '\n';
  sort(p,p+16);
  cout << p << '\n';
}
