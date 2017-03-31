//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Line.cpp
//  Implementation of Line class

#include <cmath>
#include <sstream>
#include "Point.h"
#include "Line.h"

ostream& operator<<(ostream& ostr, const Line& line)
{ return ostr << line.toString();
}

bool areParallel(const Line& line1, const Line& line2)
{ return (line1._a*line2._b == line1._b*line2._a);
}

bool arePerpendicular(const Line& line1, const Line& line2)
{ return (line1._a*line2._a + line1._b*line2._b == 0);
}

double angle(const Line& line1, const Line& line2)
{ const double PI=3.1415926535897932;
  if (areParallel(line1,line2)) return 0;
  if (arePerpendicular(line1,line2)) return PI/2;
  if (line1.isVertical()) return atan(-1.0/line2.slope());
  if (line2.isVertical()) return atan(-1.0/line1.slope());
  double m1 = line1.slope();
  double m2 = line2.slope();
  return atan((m2-m1)/(1+m1*m2));
}

//////////////////////////////////////////////////////////////////////
//  public members:

Line::Line(double x0, double y0) : _a(y0), _b(x0), _c(-x0*y0) { }

Line::Line(const Point& p, double m)
  : _a(m), _b(-1), _c(p._y-m*p._x) { }

Line::Line(const Point& p, const Point& q)
  : _a(q._y-p._y), _b(p._x-q._x), _c(q._x*p._y-p._x*q._y) { }

Line::Line(double a, double b, double c) : _a(a), _b(b), _c(c) { }

double Line::xCoef() const
{ return _a;
}

double Line::yCoef() const
{ return _b;
}

double Line::cTerm() const
{ return _c;
}

double Line::slope() const
{ return -_a/_b;
}

double Line::xIntercept() const
{ return -_c/_a;
}

double Line::yIntercept() const
{ return -_c/_b;
}

bool Line::isHorixontal() const
{ return (_a == 0);
}

bool Line::isVertical() const
{ return (_b == 0);
}

double Line::distanceTo(const Point& p) const
{ return abs(_a*p._x+_b*p._y+_c)/sqrt(_a*_a+_b*_b);
}

bool Line::contains(const Point& p) const
{ return (_a*p.x() + _b*p.y() + _c == 0);
}

string Line::toString() const
{ ostringstream out;
  out << _a << "x + " << _b << "y + " << _c << " = 0";
  return out.str();
}

//////////////////////////////////////////////////////////////////////
//  static constants:

const Line Line::X_AXIS(0,1,0);
const Line Line::Y_AXIS(1,0,0);
const Line Line::DIAGONAL(1,-1,0);
