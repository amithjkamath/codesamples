//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Deck.cpp
//  Test driver for Deck class

#include "Deck.h"

int main()
{ Deck deck;
  deck.print();
  deck.shuffle();
  deck.print();
  deck.shuffle();
  deck.print();
}
