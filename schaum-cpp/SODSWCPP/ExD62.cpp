//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.62 page 
//  Testing the swap() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{ char* p="ABCDEFGHIJ";
  cout << p << '\n';
  swap(p[2],p[8]);
  cout << p << '\n';
}
