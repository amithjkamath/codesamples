//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.13 on page 58
//  Implementation of Card class

Card::Card(Rank rank, Suit suit) : _rank(rank), _suit(suit)
{ ++_count[_rank][_suit];
}

Card::~Card()
{ --_count[_rank][_suit];
}

int Card::count() const
{ return _count[_rank][_suit];
}

bool Card::operator<(const Card& card) const
{ return _rank<card._rank || _rank==card._rank && _suit<card._suit;
}

int Card::_count[15][4]={{0}};