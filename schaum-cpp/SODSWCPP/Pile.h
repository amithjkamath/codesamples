//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Pile.h
//  Interface for Pile class

#ifndef PILE_H
#define PILE_H
#include "Card.h"

class Pile
{ // instances represent piles of playing cards
  public:
    Pile(int=0);
    ~Pile();
    void print() const;
  protected:
    void moveTo(Pile&,int)
    int _size;  // the number of cards in this pile
    Card** _card;  // an array of pointers to cards
};

Pile::Pile(int size) : _size(size)
{ _card = new Card*[_size];
}

Pile::~Pile() { delete [] _card; }

void Pile::print() const
{ for (int i=0; i<_size; i++)
    cout << _card[i]->abbr() << (i%13==12?"\n":" ");
  cout << "\n";
}

void Pile::moveTo(Pile& pile, int i)
{ if (i < 0 || i >= _size) return;
  
////////////////////////////////////////////

//  **** USE VECTORS ! !  ****
  
////////////////////////////////////////////
}

#endif  // PILE_H
