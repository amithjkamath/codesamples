//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Pile.cpp
//  Implementation of Pile class

#include "Pile.h"

//////////////////////////////////////////////////////////////////////
//  nonstatic public members:

Pile::Pile() : _size(0) { }

Pile::~Pile() { delete [] _card; }

void Pile::print() const
{ for (int i=0; i<_size; i++)
    cout << _card[i]->abbr() << (i%13==12?"\n":" ");
  cout << "\n";
}
