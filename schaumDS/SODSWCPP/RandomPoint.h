//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  RandomPoint.h
//  Interface for RandomPoint class

#ifndef RANDOM_POINT_H
#define RANDOM_POINT_H
#include "Point.h"
#include "Random.h"

class RandomPoint : public Point
{ // instances represent randomly selected points in the cartesian plane
  public:
    RandomPoint(double=1.0,double=1.0,double=0.0,double=0.0);
  protected:
    double _xMin, _xMax, _yMin, _yMax;
    static Random _random;
};

#endif  // RANDOM_POINT_H
