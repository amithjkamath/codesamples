//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.1 on page 47
//  Interface for Point class

#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;

class Point
{ public:
    Point(double=0.0,double=0.0);    // default constructor
    Point(const Point&);             // copy constructor
    ~Point();                        // destructor
    Point& operator=(const Point&);  // assignment operator
    double x() const;
    double y() const;
    string toString() const;
  private:
    double _x, _y;
};

#endif  // POINT_H
