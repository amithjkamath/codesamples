//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Hand.cpp
//  Test driver for Hand class

#include "Hand.h"

int main()
{ Deck deck;
  deck.print();
  deck.shuffle();
  deck.print();
  deck.shuffle();
  deck.print();
  Hand hand1;
  hand1.dealFrom(deck,5);
  hand1.print();
}
