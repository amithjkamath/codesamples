//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.5 on page 53
//  Overloading the output operator

class Point
{   friend ostream& operator<<(ostream&, const Point&);
  public:
    Point(double=0.0,double=0.0);         // default constructor
    Point(const Point&);                  // copy constructor
    Point& operator=(const Point&);       // assignment operator
    double x() const;
    double y() const;
    string toString() const;
  protected:
    double _x, _y;
};

ostream& operator<<(ostream& ostr, const Point& point)
{ return ostr << point.toString();
}
