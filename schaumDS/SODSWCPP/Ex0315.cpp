//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.15 on page 59
//  Interface for Deck class

class Deck
{ public:
    Deck();
    void print() const;
    void shuffle() const;
  protected:
    Card** _card;  // an array of pointers
    static const int _SIZE;
    static Random _random;  // random number generator
};
