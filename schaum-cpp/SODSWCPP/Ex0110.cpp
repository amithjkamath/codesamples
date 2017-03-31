//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 1.10 on page 8
//  Using a for loop to add reciprocals

#include <iostream>
using namespace std;

int main()
{ const int N=100;
  double sum=0.0;
  for (int x=1; x <= N; x++)
    sum += 1.0/x;
  cout << "The sum of the first " << N << " reciprocals is " << sum;
}
