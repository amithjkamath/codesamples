//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.1 on page 13
//  The maximum of four integers

#include <iostream>   // defines cin and cout objects
using namespace std;  // obviates the std:: prefix

int main()
{ int n1, n2, n3, n4;
  cout << "Enter four integers: ";
  cin >> n1 >> n2 >> n3 >> n4;
  int max=n1;
  if (n2 > max) max = n2;
  if (n3 > max) max = n3;
  if (n4 > max) max = n4;
  cout << "Their maximum is " << max << "\n";
}
