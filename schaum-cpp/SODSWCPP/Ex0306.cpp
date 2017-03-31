//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.6 on page 54
//  Interface for Line class

class Line
{ public:
    Line(double=1.0,double=1.0);      // two-intercept form of a line
    Line(const Point&, double=0.0);     // point-slope form of a line
    Line(const Point&, const Point&);     // two-point form of a line
    Line(double,double,double);    // general form of a line
    Line(const Line&);             // copy constructor
    ~Line();                       // destructor
    Line& operator=(const Line&);  // assignment operator
    double xCoef() const;
    double yCoef() const;
    double cTerm() const;
    string toString() const;
  protected:
    double _a, _b, _c;    // coefficients in general form: ax+by+c=0
};
