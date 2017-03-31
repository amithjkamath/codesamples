//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.10 on page 56
//  Test driver for Random class

#include <iostream>
using namespace std;

int main()
{ Random random;
  for (int i=0; i<25; i++)
    cout << random.integer(100) << " ";
  cout << "\n";
  for (int i=0; i<8; i++)
    cout << random.real() << " ";
  cout << "\n";
  int count[5]={0};
  for (int j=0; j<100000; j++)
    ++count[random.integer(4,0)];
  for (int i=0; i<5; i++)
    cout << "count[" << i << "] = " << count[i] << "\n";
}
