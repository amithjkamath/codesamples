//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.66 page 
//  Testing the upper_bound() algorithm

#include <algorithm>
#include <iostream>
using namespace std;

int main()
{ int a[] = {11,22,22,33,44,44,44,55,66};
  int* p = upper_bound(a,a+9,44);
  cout << "*p=" << *p << '\n';
  cout << "p-a=" << p-a << '\n';
}
