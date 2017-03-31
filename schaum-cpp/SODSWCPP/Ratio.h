//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Ratio.h
//  Interface for Ratio class

#ifndef RATIO_H
#define RATIO_H
#include <iostream>
using namespace std;

class Ratio
{ // instances represent fractions
    friend ostream& operator<<(ostream&, const Ratio&);
    friend istream& operator>>(istream&, Ratio&);
    friend Ratio operator+(const Ratio&, const Ratio&);
    friend Ratio operator-(const Ratio&, const Ratio&);
    friend Ratio operator*(const Ratio&, const Ratio&);
    friend Ratio operator/(const Ratio&, const Ratio&);
  public:
    Ratio(long=0,long=1);
    long numerator() const;
    long denominator() const;
    Ratio reciprocal() const;
    void invert();
    operator double() const;
  private:
    long _num;
    long _den;
    long gcd(long,long);
    void reduce();
    // INVARIANT: _den > 0 && gcd(_num,_den) == 1
};

#endif  // RATIO_H

