//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Hand.cpp
//  Implementation of Hand class

#include "Hand.h"

//////////////////////////////////////////////////////////////////////
//  nonstatic public members:

Hand::Hand() : _size(0) { }

void Hand::print() const
{ for (int i=0; i<_size; i++)
    cout << _card[i]->abbr() << (i%13==12?"\n":" ");
  cout << "\n";
}

Hand& Hand::operator=(const Hand& hand)
{ _size = hand._size;
  _card = new Card*[_size];
  for (int i=0; i<_size; i++)
    _card[i] = hand._card[i];
}

Hand::~Hand()
{ delete [] _card;
}
/*
void Hand::drawFrom(Hand& hand, int n)
{ // draws n cards at random from hand into this hand
  Card** tmp = new Card*[_size];
  for (int i=0; i<_size; i++)
    tmp[i] = hand._card[i];
  
  _card = new Card*[n];
  for (int i=0; i<n; i++)
  { cout << "Dealing the " << *deck._card[deck._top] << ".\n";
    _card[_size++] = deck._card[deck._top++];
  }
  cout << "\n";
}
*/