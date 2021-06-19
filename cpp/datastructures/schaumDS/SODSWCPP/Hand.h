//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Hand.h
//  Interface for Hand class

#ifndef HAND_H
#define HAND_H
#include "Pile.h"

class Hand : public Pile
{ // instances represent hands of playing cards
  public:
    Hand(int);
};

Hand::Hand(int size) : Pile(size) { }

#endif  // HAND_H
