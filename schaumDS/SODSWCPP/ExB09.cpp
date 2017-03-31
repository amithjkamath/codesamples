//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example B.9 page 280
//  Euler's Constant

#include <iomanip>
#include <iostream>
using namespace std;

int main()
{ cout.setf(ios::right,ios::adjustfield);
  cout << setiosflags(ios::fixed) << setprecision(10);
  cout << "      n           H(n)          ln(n)       H(n)-ln(n)\n";
  cout << "  ---------  -------------  -------------  ------------\n";
  double h=0.0;          // harmonic numbers
  int pow2=1;            // powers of  2
  for (int n=1; n<1e9; n++)
  { h += 1.0/n;          // add reciprocals
    if (n==pow2)         // print only for powers of 2:
    { double ln=log(n);  // natural logarithm (base e)
      cout << setw(11) << n << setw(15) << h << setw(15) << ln
           << setw(14) << h-ln << endl;
      pow2 *= 2;
    }
  }
  cout << "  ---------  -------------  -------------  ------------\n";
}
