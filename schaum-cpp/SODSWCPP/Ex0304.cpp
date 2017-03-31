//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.4 on page 51
//  Complete Point class definition and test driver

#include <iostream>
#include <sstream>  // defines the ostringstream class
using namespace std;

class Point
{ public:
    Point(double x=0.0, double y=0.0) : _x(x), _y(y) { }
    Point(const Point& p) : _x(p._x), _y(p._y) { }
    ~Point() { }
    Point& operator=(const Point& p)
    { _x = p._x;
      _y = p._y;
      return *this;
    }
    double x() const { return _x; }
    double y() const { return _y; }
    string toString() const
    { ostringstream output;
      output << "(" << _x << "," << _y << ")";
      return output.str();
    }
  protected:
    double _x, _y;
};

int main()
{ Point p0;                // invokes default constructor
  cout << "p0 = " << p0.toString() << "\n";
  Point p1(5,-2);         // invokes default constructor
  cout << "p1 = " << p1.toString() << "\n";
  Point p2=p1;            // invokes copy constructor
  cout << "p2 = " << p2.toString() << "\n";
  p0 = p1;                // invokes assignment operator
  cout << "p0 = " << p0.toString() << "\n";
  cout << "p0.x() = " << p0.x() << "\n";
  cout << "p0.y() = " << p0.y() << "\n";
}
