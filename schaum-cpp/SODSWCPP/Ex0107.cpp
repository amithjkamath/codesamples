//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 1.7 on page 6
//  Using a goto to add reciprocals

#include <iostream>
using namespace std;

int main()
{ const int N=100;
  double sum=0.0;
  int x=1;
  repeat: sum += 1.0/x++;
  if (x <= N) goto repeat;
  cout << "The sum of the first " << N << " reciprocals is " << sum;
}
