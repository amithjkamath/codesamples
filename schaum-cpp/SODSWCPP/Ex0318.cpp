//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 3.18 on page 61
//  Monte Carlo simulation

#include <iostream>
using namespace std;

int main()
{ const int SHOTS=10000000;  // 10M
  int hits=0;
  for (int i=0; i<SHOTS; i++)
  { RandomPoint p0(1,1,-1,-1);  // -1 <= x <= 1 and -1 <= y <= 1
    double x = p0.x();
    double y = p0.y();
    if (x*x+y*y<1) ++hits;
  }
  cout << "SHOTS = " << SHOTS << "\n";
  cout << "hits = " << hits << "\n";
  cout << "pi = " << 4.0*hits/SHOTS << "\n";
}
