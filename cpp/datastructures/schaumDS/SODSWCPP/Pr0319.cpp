//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.19 on page 66
//  A complete implementation of the Card class

#include "Card.h"

ostream& operator<<(ostream& ostr, const Card& card)
{ return ostr << card.toString();
}

Card::Card(Rank rank, Suit suit) : _rank(rank), _suit(suit)
{ ++_count[_rank][_suit];
}

Card::Card(int r, int s) : _rank(Rank(r)), _suit(Suit(s))
{ ++_count[_rank][_suit];
}

Card::Card(const Card& card) : _rank(card._rank), _suit(card._suit)
{ ++_count[_rank][_suit];
}

Card::~Card() { --_count[_rank][_suit]; }

Card::Rank Card::rank() const { return _rank; }

Card::Suit Card::suit() const { return _suit; }

bool Card::isFaceCard() const { return (_rank > NINE); }

int Card::count() const { return _count[_rank][_suit]; }

string Card::toString() const
{ string str;
  switch (_rank)
  { case TWO:   str = "two of ";  break;
    case THREE: str = "three of ";   break;
    case FOUR:  str = "four of ";   break;
    case FIVE:  str = "five of ";   break;
    case SIX:   str = "six of ";    break;
    case SEVEN: str = "seven of ";  break;
    case EIGHT: str = "eight of ";  break;
    case NINE:  str = "nine of ";   break;
    case TEN:   str = "ten of ";    break;
    case JACK:  str = "jack of ";   break;
    case QUEEN: str = "queen of ";  break;
    case KING:  str = "king of ";   break;
    default:    str = "ace of ";
  }
  switch (_suit)
  { case CLUB:    str += "clubs";     break;
    case DIAMOND: str += "diamonds";  break;
    case HEART:   str += "hearts";    break;
    default:      str += "spades";
  }
  return str;
}

string Card::abbr() const
{ string str;
  switch (_rank)
  { case TWO:   str = "2";  break;
    case THREE: str = "3";  break;
    case FOUR:  str = "4";  break;
    case FIVE:  str = "5";  break;
    case SIX:   str = "6";  break;
    case SEVEN: str = "7";  break;
    case EIGHT: str = "8";  break;
    case NINE:  str = "9";  break;
    case TEN:   str = "T";  break;
    case JACK:  str = "J";  break;
    case QUEEN: str = "Q";  break;
    case KING:  str = "K";  break;
    default:    str = "A";
  }
  switch (_suit)
  { case CLUB:    str += "C";  break;
    case DIAMOND: str += "D";  break;
    case HEART:   str += "H";  break;
    default:      str += "S";
  }
  return str;
}

bool Card::operator<(const Card& card) const
{ return _rank<card._rank || _rank==card._rank && _suit<card._suit;
}

bool Card::operator>(const Card& card) const
{ return _rank>card._rank || _rank==card._rank && _suit>card._suit;
}

bool Card::operator<=(const Card& card) const
{ return _rank<=card._rank || _rank==card._rank && _suit<=card._suit;
}

bool Card::operator>=(const Card& card) const
{ return _rank>=card._rank || _rank==card._rank && _suit>=card._suit;
}

bool Card::operator==(const Card& card) const
{ return _rank == card._rank && _suit == card._suit;
}

bool Card::operator!=(const Card& card) const
{ return _rank != card._rank || _suit != card._suit;
}

int Card::_count[15][4]={{0}};
