//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.1 on page 64
//  Testing the Point class constructors

#include <iostream>
#include <sstream>  // defines ostringstream class
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

int main()
{ Point p0;  // invokes default constructor
  Point p1(1);  // invokes default constructor
  Point p2=p1;  // initialization invokes copy constructor
  p1 = Point(5,-2);  // assignment invokes assignment operator
}

Point::Point(double x, double y) : _x(x), _y(y)
{ cout << "DEFAULT CONSTRUCTOR INVOKED ON " << this->toString() << "\n";
}

Point::Point(const Point& p) : _x(p._x), _y(p._y)
{ cout << "COPY CONSTRUCTOR INVOKED ON " << this->toString() << "\n";
}

Point::~Point()
{ cout << "DESTRUCTOR INVOKED ON " << this->toString() << "\n";
}

Point& Point::operator=(const Point& point)
{ cout << "ASSIGNMENT OPERATOR INVOKED ON " << this->toString() << "\n";
  _x = point._x;
  _y = point._y;
  return *this;
}

double Point::x() const
{ return _x;
}

double Point::y() const
{ return _y;
}

string Point::toString() const
{ ostringstream out;
  out << "(" << _x << "," << _y << ")";
  return out.str();
}
