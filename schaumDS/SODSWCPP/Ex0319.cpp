//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.19 on page 62
//  Interface for RandomPoint class

class RandomPoint : public Point
{ // instances represent randomly selected points in the plane
  public:
    RandomPoint(double=1.0,double=1.0,double=0.0,double=0.0);
  protected:
    double _x1, _x2, _y1, _y2;
    static Random _random;
};
