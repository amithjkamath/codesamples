//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.10 on page 65
//  More member functions for the Line class

bool Line::isHorixontal() const { return (_a == 0); }
bool Line::isVertical() const { return (_b == 0); }
