//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.14 page 417
//  Testing the find_first_of() algorithm

#include <algorithm>
#include "Odd.h"

int main()
{ int a[] = {0,1,1,2,3,5,8,13,21,34};
  int b[] = {6,7,8,9,10,11,12,13,14,15};
  int* r = find_first_of(a,a+10,b,b+10);
  cout << "*r=" << *r << '\n';    // this is the element a[i]
  cout << "r-a=" << r-a << '\n';  // this is the index i
}
