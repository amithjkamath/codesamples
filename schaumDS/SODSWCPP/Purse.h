//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Purse.h
//  Interface for Purse class

#ifndef PURSE_H
#define PURSE_H
#include <iostream>
using namespace std;

class Purse
{ // instances represent purses containing coins
  public:
    Purse(int=0,int=0,int=0,int=0);
    int pennies() const;
    int nickels() const;
    int dimes() const;
    int quarters() const;
    float value() const;
    void insert(float);
    void remove(float);
    float empty();
    bool isEmpty() const;
  private:
    int _pennies;
    int _nickels;
    int _dimes;
    int _quarters;
    void reduce();
    //  INVARIANTS: 0 <= _pennies < 5
    //              0 <= _nickels < 2
    //              0 <= dimes < 3
    //              0 <= _quarters
};

#endif  // PURSE_H
