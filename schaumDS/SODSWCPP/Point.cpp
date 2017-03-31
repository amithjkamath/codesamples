//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Point.cpp
//  Implementation of Point class

#include <cmath>  // defines sqrt() function
#include <sstream>  // defines ostringstream class
#include "Point.h"
#include "Line.h"

//////////////////////////////////////////////////////////////////////
//  friend functions:

ostream& operator<<(ostream& ostr, const Point& point)
{ return ostr << point.toString();
}

Point operator-(const Point& point)
{ return Point(-1*point._x,-1*point._y);
}

Point operator+(const Point& p1, const Point& p2)
{ return Point(p1._x+p2._x,p1._y+p2._y);
}

Point operator-(const Point& p1, const Point& p2)
{ return Point(p1._x-p2._x,p1._y-p2._y);
}

Point operator*(const double coef, const Point& point)
{ return Point(coef*point._x,coef*point._y);
}

Point operator/(const Point& point, const double divisor)
{ return Point(point._x/divisor,point._y/divisor);
}

double distance(const Point& p1, const Point& p2)
{ float dx=(p1._x-p2._x);
  float dy=(p1._y-p2._y);
  return sqrt(dx*dx+dy*dy);
}

//////////////////////////////////////////////////////////////////////
//  public members:

Point::Point(double x, double y) : _x(x), _y(y) { }

Point::Point(const Point& p) : _x(p._x), _y(p._y) { }

Point& Point::operator=(const Point& point)
{ _x = point._x;
  _y = point._y;
  return *this;
}

bool Point::operator==(const Point& point) const
{ return _x == point._x && _y == point._y;
}

bool Point::operator!=(const Point& point) const
{ return _x != point._x || _y != point._y;
}

Point& Point::operator+=(const Point& point)
{ _x += point._x;
  _y += point._y;
  return *this;
}

Point& Point::operator-=(const Point& point)
{ _x -= point._x;
  _y -= point._y;
  return *this;
}

Point& Point::operator*=(const double c)
{ _x *= c;
  _y *= c;
  return *this;
}

Point& Point::operator/=(const double c)
{ _x /= c;
  _y /= c;
  return *this;
}

double Point::x() const
{ return _x;
}

double Point::y() const
{ return _y;
}

double Point::magnitude() const
{ return sqrt(_x*_x+_y*_y);
}

double Point::amplitude() const
{ return atan(_y/_x);
}

void Point::rotate(double alpha)
{ double r = magnitude();
  double theta = amplitude() + alpha;
  _x = r*cos(theta);
  _y = r*sin(theta);
}

double Point::distanceTo(const Line& line) const
{ double a = line._a;
  double b = line._b;
  double c = line._c;
  return abs(a*_x+b*_y+c)/sqrt(a*a+b*b);
}

bool Point::isOn(const Line& line) const
{ double a = line._a;
  double b = line._b;
  double c = line._c;
  return (a*_x + b*_y + c == 0);
}

string Point::toString() const
{ ostringstream out;
  out << "(" << _x << "," << _y << ")";
  return out.str();
}

const Point Point::ORIGIN(0,0);
