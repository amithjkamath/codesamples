//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example D.1 page 411
//  Testing the accumulate() algorithm

#include <iostream>
#include <numeric>
using namespace std;

int main()
{ int a[] = {0,1,1,2,3,5,8,13,21,34};
  int sum = accumulate(a,a+10,1000);
  cout << "sum=" << sum << '\n';
}
