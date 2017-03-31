//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Card.cpp
//  Test driver for Card class

#include <iomanip>
#include "Card.h"

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
  cout << "c1 = " << c1 << ", c1.count() = " << c1.count() << "\n";
  cout << "(c1 < c4) = " << (c1 < c4) << "\n";
  cout << "(c1 > c4) = " << (c1 > c4) << "\n";
  c1 = Card(Card::SIX,Card::CLUB);
  cout << "c1 = " << c1 << ", c1.count() = " << c1.count() << "\n";
  cout << "c2 = " << c2 << ", c2.count() = " << c2.count() << "\n";
  cout << "(c1 < c4) = " << (c1 < c4) << "\n";
  cout << "(c1 > c4) = " << (c1 > c4) << "\n";
  for (int s=3; s>=0; s--)
    for (int r=12; r>=0; r--)
      cout << Card(r,s).abbr() << (r?" ":"\n");
}
