//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.20 on page 66
//  A different RandomPoint class

class RandomPoint
{ // instances represent randomly selected points in the plane
  public:
    RandomPoint(double=0.0,double=0.0);   // default constructor
    RandomPoint(double,double,double,double);
    double x() const;
    double y() const;
    string toString() const;
  protected:
    double _x, _y, _x1, _x2, _y1, _y2;
    static Random _random;
};
