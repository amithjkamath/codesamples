//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Random.h
//  Interface for Random class

#ifndef RANDOM_H
#define RANDOM_H
#include <climits>  // defines INT_MAX and ULONG_MAX constant
#include <iostream>
using namespace std;

class Random
{ // instances represent random number generators
  public:
    Random(unsigned long=0);
    void reset_seed(unsigned long=0);
    int integer(unsigned long=ULONG_MAX,unsigned long=1);
    double real();
  private:
    unsigned long _seed;
    void randomize();
    //  INVARIANT: 0 <= _seed < ULONG_MAX
};

#endif  // RANDOM_H
