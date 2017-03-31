//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Deck.h
//  Interface for Deck class

#ifndef DECK_H
#define DECK_H
#include <iostream>
#include "Card.h"
#include "Random.h"
using namespace std;

class Deck
{ // instances represent ordinary decks of playing cards
  public:
    Deck();
    void print() const;
    void shuffle() const;
  protected:
    static const int _SIZE;
    Card** _card;  // an array of pointers
    static Random _random;  // random number generator
};

#endif  // DECK_H
