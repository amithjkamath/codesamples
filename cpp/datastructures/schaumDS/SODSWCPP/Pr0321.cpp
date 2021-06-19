//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 3.21 on page 66
//  A different RandomLine class

#include <iostream>
using namespace std;

class RandomLine : public Line
{ // instances represent randomly selected lines in the cartesian plane
  public:
    RandomLine();
  protected:
    static Random _random;
};

////////////////////////////////////////////////////////////////
//  Test driver:

int main()
{ RandomLine line0;
  cout << "line0: " << line0 << "\n";
  RandomLine line1;
  cout << "line1: " << line1 << "\n";
  line0 = RandomLine();
  cout << "line0: " << line0 << "\n";
}

////////////////////////////////////////////////////////////////
//  Implementation:

RandomLine::RandomLine()
{ _a = _random.real();
  _b = _random.real();
  _c = _random.real();
}

Random RandomLine::_random;
