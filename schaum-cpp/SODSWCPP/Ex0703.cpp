//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 7.3 on page 130
//  Interface for a Polynomial class: Polynomial.h

#include <iostream>
#include <list>
using namespace std;

class Polynomial
{ protected:
    struct Term
    { friend ostream& operator<<(ostream&, const Term&);
      Term(double=0.0,unsigned=0);
      bool operator==(const Term&) const;
      bool operator<(const Term&) const;
      double _coef;
      unsigned _exp;
    };
  public:
    friend ostream& operator<<(ostream&, const Polynomial&);
    friend Polynomial operator*(const double, const Polynomial&);
    friend Polynomial operator+(const Polynomial&, const Polynomial&);
    Polynomial(double=0,unsigned=0);
    Polynomial(const Polynomial&);
    Polynomial& operator=(const Polynomial&);
    bool operator==(const Polynomial&) const;
    double operator()(double) const;  // evaluates the polynomial
    long degree() const;
    unsigned terms() const;  // the number of terms in the polynomial    static const Polynomial ZERO;  // p(x) = 0
  protected:
    list<Term> _terms;  // one element for each term
    long _degree;       // maximum exponent
    void reduce();      // collect terms
    typedef list<Term> TermList;
    typedef list<Term>::iterator It;
    typedef list<Term>::const_iterator CIt;
};
