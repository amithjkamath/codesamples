//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.18 on page 15
//  Tests the sum of digits function

#include <iostream>
using namespace std;
int digitSum(int); 

int main()
{ int n;
  cout << "Enter a positive integer: ";
  cin >> n;
  cout << "digitSum(n) = " << digitSum(n) << "\n";
}

int digitSum(int n)
{ int sum=0;
  while (n>0)
  { sum += n%10;
    n /= 10;
  }
  return sum;
}
