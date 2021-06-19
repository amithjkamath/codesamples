//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.16 on page 15
//  Tests the isLeap(year) function

#include <iostream>
using namespace std;
bool isLeap(int); 

int main()
{ cout << "isLeap(1900) = " << isLeap(1900) << "\n";
  cout << "isLeap(1996) = " << isLeap(1996) << "\n";
  cout << "isLeap(1999) = " << isLeap(1999) << "\n";
  cout << "isLeap(2000) = " << isLeap(2000) << "\n";
}

bool isLeap(int y)
{ if (y%400==0) return true;
  if (y%100==0) return false;
  if (y%4==0) return true;
  return false;
}
