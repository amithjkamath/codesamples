//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.19 page 
//  Testing the includes() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{ int a[] = {0,1,1,2,3,5,8,13,21,34};
  int b[] = {0,1,2,3,4};
  bool found = includes(a,a+10,b,b+5);
  cout << "found=" << found << '\n';
  found = includes(a,a+10,b,b+4);
  cout << "found=" << found << '\n';
}
