//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.13 page 417
//  Testing the find_end() algorithm

#include <algorithm>
#include "Odd.h"

int main()
{ int a[] = {0,1,0,1,1,1,0,1,1,0};
  int b[] = {1,0,1,1,1};
  int* r = find_end(a,a+10,b,b+5);
  cout << "*r=" << *r << '\n';    // this is the element a[i]
  cout << "r-a=" << r-a << '\n';  // this is the index of i
  r = find_end(a,a+10,b,b+4);
  cout << "*r=" << *r << '\n';    // this is the element a[i]
  cout << "r-a=" << r-a << '\n';  // this is the index of i
}
