//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 1.3 on page 13
//  Solving quadratic equations more robustly

#include <cmath>  // defines the sqrt() function
#include <iostream>
using namespace std;

int main()
{ // implements the quadratic formula
  double a, b, c;
  cout << "Enter the coefficients of a quadratic equation:" << endl;
  cout << "\ta: ";  cin >> a;
  cout << "\tb: ";  cin >> b;
  cout << "\tc: ";  cin >> c;
  cout << "The equation is: " << a << "*x*x + " << b
       << "*x + " << c << " = 0\n";
  if (a == 0.0)
  { if (b == 0.0)
      if (c == 0.0) cout << "Every x satisfies that equation.\n";
      else cout << "No x satisfies that equation.\n";
    else cout << "The unique solution is: x = " << -c/b << endl;
    return 0;
  }
  double d = b*b - 4*a*c;  // discriminant
  if (d < 0)
  { cout << "The discriminant, d = " << d
         << " < 0, so there are no real solutions.\n";
    return 0;
  }
  double sqrtd = sqrt(d);
  double x1 = (-b + sqrtd)/(2*a);
  double x2 = (-b - sqrtd)/(2*a);
  cout << "The solutions are:\n";
  cout << "\tx1 = " << x1 << endl;
  cout << "\tx2 = " << x2 << endl;
  cout << "Check:";
  cout << "\ta*x1*x1 + b*x1 + c = " <<  a*x1*x1 + b*x1 + c;
  cout << "\n\ta*x2*x2 + b*x2 + c = " <<  a*x2*x2 + b*x2 + c;
}
