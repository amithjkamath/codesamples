//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  RandomPoint.cpp
//  Implementation of RandomPoint class

#include "RandomPoint.h"

RandomPoint::RandomPoint(double xMax, double yMax, double xMin, double yMin)
  : _xMax(xMax), _yMax(yMax), _xMin(xMin), _yMin(yMin)
{ double x = _random.real();
  _x = (_xMax-_xMin)*x + _xMin;
  double y = _random.real();
  _y = (_yMax-_yMin)*y + _yMin;
}

Random RandomPoint::_random;
