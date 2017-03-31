//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 7.8 page 138
//  Interface for the Integer class: Integer.h

#include <iostream>
#include <list>     // defines list class template
using namespace std;

class Integer
{ // instances represent arbitrarily large integers;
  // INVARIANTS: positive integers are stored in a list named _,
  //             with WIDTH digits per element;
  //             negative integers are stored as positive integers
  //             with _neg == true;
  public:
    friend ostream& operator<<(ostream&, const Integer&);
    friend Integer operator+(const Integer&, const Integer&);
    friend Integer operator*(const Integer&, const Integer&);
    friend int sign(const Integer&);  // -1, 0, or 1
    Integer(const int=0);
    Integer(const string&);
    bool operator==(const Integer&) const;
    bool operator<(const Integer&) const;
    string toString() const;
    static const Integer ZERO;
    static const int WIDTH;    // number of digits per list element
    static const int RADIX;    // number of values per list element
  protected:
    static string pad(string);  // pad on left with 0s to len=9
    static Integer NotAnInteger();
    static string toString(int);
    static Integer toInteger(string);
    typedef list<int> List;
    typedef List::iterator It;
    typedef List::const_iterator CIt;
    typedef List::reverse_iterator RIt;
    typedef List::const_reverse_iterator CRIt;
    bool _neg;  // true iff this is negative
    List _;     // list of positive WIDTH-digit integers
};
