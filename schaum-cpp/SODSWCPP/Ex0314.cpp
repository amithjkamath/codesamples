//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.14 on page 59
//  Test driver for Card class

#include <iostream>
using namespace std;

int main()
{ Card c1;
  cout << "c1 = " << c1 << ", c1.count() = " << c1.count() << "\n";
  Card c2;
  cout << "c2 = " << c2 << ", c2.count() = " << c2.count() << "\n";
  cout << "c1 = " << c1 << ", c1.count() = " << c1.count() << "\n";
  { Card c3;
    cout << "c3 = " << c3 << ", c3.count() = " << c3.count() << "\n";
  }
  cout << "c1 = " << c1 << ", c1.count() = " << c1.count() << "\n";
  Card c4(Card::SIX,Card::HEART);
  cout << "c4 = " << c4 << ", c4.count() = " << c4.count() << "\n";
}
