//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.2 on page 13
//  The median of five integers

#include <iostream>   // defines cin and cout objects
using namespace std;  // obviates the std:: prefix

int main()
{ int n, n1, n2, n3;
  cout << "Enter five integers: ";
  cin >> n;
  n1 = n;
  cin >> n;
  if (n < n1) { n2 = n1; n1 = n; }
  else n2 = n;  // now n1 <= n2
  cin >> n;
  if (n < n1) { n3 = n2; n2 = n1; n1 = n; }
  else if (n < n2) { n3 = n2; n2 = n; }
  else n3 = n;  // now n1 <= n2 <= n3
  cin >> n;
  if (n < n1) { n3 = n2; n2 = n1; n1 = n; }
  else if (n < n2) { n3 = n2; n2 = n; }
  else if (n < n3) n3 = n;  // now n1 <= n2 <= n3 <= other n
  cin >> n;
  if (n < n1) { n3 = n2; n2 = n1; n1 = n; }
  else if (n < n2) { n3 = n2; n2 = n; }
  else if (n < n3) n3 = n;  // now n1 <= n2 <= n3 <= other n's
  cout << "Their median is " << n3 << "\n";
}
