//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 1.6 on page 4
//  The conditional expression operator

#include <iostream>
using namespace std;

int main()
{ // prints the maximum of two given integers
  int m, n;
  cout << "Enter two integers: ";  cin >> m >> n;
  cout << "Their maximum is " << ( m>n ? m : n );
}
