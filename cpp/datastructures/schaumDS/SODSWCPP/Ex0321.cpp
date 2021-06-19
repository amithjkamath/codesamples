//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.21 on page 63
//  Implementation of RandomPoint class

RandomPoint::RandomPoint(double x2, double y2, double x1, double y1)
  : _x2(x2), _y2(y2), _x1(x1), _y1(y1)
{ double x = _random.real();
  _x = (_x2 - _x1)*x + _x1;
  double y = _random.real();
  _y = (_y2 - _y1)*y + _y1;
}

Random RandomPoint::_random;
