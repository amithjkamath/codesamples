//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.16 on page 60
//  Test driver for Deck class

#include <iostream>
using namespace std;

int main()
{ Deck deck;
  deck.print();    // prints all 52 cards
  deck.shuffle();  // shuffles the deck
  deck.print();
  deck.shuffle();
  deck.print();
}