//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.15 page 
//  Testing the finr_if() algorithm

#include <algorithm>
#include "Odd.h"

int main()
{ int a[] = {2,4,8,16,32,64,128,256,333,512};
  int* r = find_if(a,a+10,Odd());
  cout << "*r=" << *r << '\n';    // this is the element a[i]
  cout << "r-a=" << r-a << '\n';  // this is the index of i
  r = find_if(a,a+5,Odd());
  cout << "*r=" << *r << '\n';    // this is the element a[i]
  cout << "r-a=" << r-a << '\n';  // this is the index of i
}
