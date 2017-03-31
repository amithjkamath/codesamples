//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Polynomial.h
//  Interface for Polynomial class

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <list>
using namespace std;

class Polynomial
{ // instances represent polynomials; e.g., 2x^7 - 8x^3 + 5x^2 + 9
  // INVARIANTS: _degree == _terms.begin()._exp;
  //             it1->_exp == it2->_exp  ==>  it1 == it2
  //             *this == ZERO  <==>  _degree == -1
  //                            <==>  _terms.size() == 0;
  protected:
    struct Term
    { friend ostream& operator<<(ostream&, const Term&);
      friend Term operator-(const Term&);
      friend Term derivative(const Term&);
      friend Term antiderivative(const Term&);
      friend Term abs(const Term&);
      Term(double=0.0,unsigned=0);
      bool operator==(const Term&) const;
      bool operator!=(const Term&) const;
      bool operator<(const Term&) const;
      double _coef;
      unsigned _exp;
    };
  public:
    friend ostream& operator<<(ostream&, const Polynomial&);
    friend Polynomial operator-(const Polynomial&);
    friend Polynomial operator*(const double, const Polynomial&);
    friend Polynomial operator+(const Polynomial&, const Polynomial&);
    friend Polynomial operator-(const Polynomial&, const Polynomial&);
    friend Polynomial operator*(const Polynomial&, const Polynomial&);
    friend Polynomial derivative(const Polynomial&);
    friend Polynomial antiderivative(const Polynomial&);
    Polynomial(double=0,unsigned=0);
    Polynomial& operator+=(const Polynomial&);
    Polynomial& operator-=(const Polynomial&);
    Polynomial& operator*=(const double);
    Polynomial& operator*=(const Polynomial&);
    bool operator==(const Polynomial&) const;
    bool operator!=(const Polynomial&) const;
    double operator()(double) const;  // evaluates the polynomial
    long degree() const;
    unsigned terms() const;  // the number of terms in the polynomial
    static const Polynomial ZERO;  // p(x) = 0
    static const Polynomial ONE;   // p(x) = 1
    static const Polynomial X;     // p(x) = x
  protected:
    list<Term> _terms;   // one element for each term
    long _degree;        // maximum exponent
    void reduce();
    typedef list<Term> TermList;
    typedef list<Term>::iterator It;
    typedef list<Term>::const_iterator CIt;
};

#endif  // POLYNOMIAL_H
