//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  RandomLine.cpp
//  Implementation of RandomLine class

#include "RandomLine.h"

RandomLine::RandomLine()
{ _a = _random.real();
  _b = _random.real();
  _c = _random.real();
}

Random RandomLine::_random;
