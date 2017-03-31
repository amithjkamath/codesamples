//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Line.h
//  Interface for Line class

#ifndef LINE_H
#define LINE_H
#include <iostream>
using namespace std;

class Line
{ // instances represent lines in the cartesian plane
    friend class Point;
    friend ostream& operator<<(ostream&, const Line&);
    friend bool areParallel(const Line&, const Line&);
    friend bool arePerpendicular(const Line&, const Line&);
    friend double angle(const Line&, const Line&);
  public:
    Line(double=1.0, double=1.0);
    Line(const Point&, double=0.0);
    Line(const Point&, const Point&);
    Line(double,double,double);
    double xCoef() const;
    double yCoef() const;
    double cTerm() const;
    double slope() const;
    double xIntercept() const;
    double yIntercept() const;
    bool isHorixontal() const;
    bool isVertical() const;
    double distanceTo(const Point&) const;
    bool contains(const Point&) const;
    string toString() const;
    static const Line X_AXIS;    // the line y = 0
    static const Line Y_AXIS;    // the line x = 0
    static const Line DIAGONAL;  // the line y = x
  protected:
    double _a, _b, _c;  // coefficients in general form: ax+by+c=0
};

#endif  // LINE_H
