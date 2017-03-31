//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 1.8 on page 7
//  Using a do...while to add reciprocals

#include <iostream>
using namespace std;

int main()
{ const int N=100;
  double sum=0.0;
  int x=1;
  do sum += 1.0/x++;
  while (x <= N);
  cout << "The sum of the first " << N << " reciprocals is " << sum;
}
