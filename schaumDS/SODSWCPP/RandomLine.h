//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  RandomLine.h
//  Interface for RandomLine class

#ifndef RANDOM_LINE_H
#define RANDOM_LINE_H
#include "Line.h"
#include "Random.h"

class RandomLine : public Line
{ // instances represent randomly selected lines in the cartesian plane
  public:
    RandomLine();
  protected:
    static Random _random;
};

#endif  // RANDOM_LINE_H
