//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Point.h
//  Interface for Point class

#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

class Point
{ // instances represent points in the cartesian plane
    friend class Line;
    friend ostream& operator<<(ostream&, const Point&);
    friend Point operator-(const Point&);
    friend Point operator+(const Point&, const Point&);
    friend Point operator-(const Point&, const Point&);
    friend Point operator*(const double, const Point&);
    friend Point operator/(const Point&, const double);
    friend double distance(const Point&, const Point&);
  public:
    Point(double=0.0,double=0.0);         // default constructor
    Point(const Point&);                  // copy constructor
    Point& operator=(const Point&);       // assignment operator
    bool operator==(const Point&) const;  // equality operator
    bool operator!=(const Point&) const;  // inequality operator
    Point& operator+=(const Point&);
    Point& operator-=(const Point&);
    Point& operator*=(const double);
    Point& operator/=(const double);
    double x() const;
    double y() const;
    double magnitude() const;  // the polar coordinate r
    double amplitude() const;  // the polar coordinate theta
    void rotate(double);
    bool isOn(const Line&) const;
    double distanceTo(const Line&) const;
    string toString() const;
    static const Point ORIGIN;
  protected:
    double _x, _y;
};

#endif  // POINT_H
