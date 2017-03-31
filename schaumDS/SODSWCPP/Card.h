//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Card.h
//  Interface for Card class

#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;

class Card
{ // instances represent playing cards
    friend ostream& operator<<(ostream&, const Card&);
  public:
    enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
                TEN, JACK, QUEEN, KING, ACE };
    enum Suit { CLUB, DIAMOND, HEART, SPADE };
    Card(Rank=ACE,Suit=SPADE);     // default constructor
    Card(int,int);                 // constructor
    Card(const Card&);             // copy constructor
    ~Card();                       // destructor
    Rank rank() const;
    Suit suit() const;
    bool isFaceCard() const;  
    int count() const;
    string toString() const;
    string abbr() const;
    bool operator<(const Card&) const;
    bool operator>(const Card&) const;
    bool operator<=(const Card&) const;
    bool operator>=(const Card&) const;
    bool operator==(const Card&) const;
    bool operator!=(const Card&) const;
  private:
    Rank _rank;
    Suit _suit;
    static int _count[13][4];
};

#endif  // CARD_H
