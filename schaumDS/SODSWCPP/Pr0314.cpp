//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.14 on page 65
//  Another friend function for the Line class

double angle(Line& line1, Line& line2)
{ const double PI=3.1415926535897932;
  if (areParallel(line1,line2)) return 0;
  if (arePerpendicular(line1,line2)) return PI/2;
  if (line1.isVertical()) return atan(-1.0/line2.slope());
  if (line2.isVertical()) return atan(-1.0/line1.slope());
  double m1 = line1.slope();
  double m2 = line2.slope();
  return atan((m2-m1)/(1+m1*m2));
}
