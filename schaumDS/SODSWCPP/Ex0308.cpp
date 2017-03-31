//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.8 on page 55
//  Implementation of Line class

ostream& operator<<(ostream& ostr, const Line& line)
{ return ostr << line.toString();
}

Line::Line(double x0, double y0) : _a(y0), _b(x0), _c(-x0*y0) { }

Line::Line(const Point& p, double m)
  : _a(m), _b(-1), _c(p._y-m*p._x) { }
  
Line::Line(const Point& p, const Point& q)
  : _a(q._y-p._y), _b(p._x-q._x), _c(q._x*p._y-p._x*q._y) { }
  
Line::Line(double a, double b, double c) : _a(a), _b(b), _c(c) { }

Line::Line(const Line& l) : _a(l._a), _b(l._b), _c(l._c) { }

Line::~Line() { }

Line& Line::operator=(const Line& line)
{ _a = line._a;
  _b = line._b;
  _c = line._c;
  return *this;
}

double Line::xCoef() const { return _a; }

double Line::yCoef() const { return _b; }

double Line::cTerm() const { return _c; }

string Line::toString() const
{ ostringstream out;
  out << _a << "x + " << _b << "y + " << _c << " = 0";
  return out.str();
}