//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.13 on page 65
//  More member functions for the Line class

bool areParallel(Line& line1, Line& line2)
{ return (line1._a*line2._b == line1._b*line2._a);
}

bool arePerpendicular(Line& line1, Line& line2)
{ return (line1._a*line2._a + line1._b*line2._b == 0);
}
