//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.20 page 420
//  Using the accumulate() algorithm

#include <iostream>
#include <numeric>
using namespace std;

int main()
{ int a[] = {1,3,5,7,9};
  int b[] = {4,3,2,1,0};
  int dot = inner_product(a,a+4,b,0);
  cout << "dot=" << dot << '\n';
}
