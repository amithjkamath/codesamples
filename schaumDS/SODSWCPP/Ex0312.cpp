//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.12 on page 58
//  Interface for Card class

class Card
{   friend ostream& operator<<(ostream&, const Card&);
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
    static int _count[15][4];
};
