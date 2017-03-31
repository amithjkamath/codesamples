//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Time.cpp
//  Test driver for the Time class

#include "Time.h"

int main()
{ cout << "Time::MIDNIGHT = " << Time::MIDNIGHT << "\n";
  cout << "Time::NOON     = " << Time::NOON << "\n";
  cout << "Time::now()    = " << Time::now() << "\n";
  Time t1(23,9);
  cout << "t1 = " << t1 << "\n";
  cout << "t1 = " << t1 << "\n";
  --t1;
  cout << "t1 = " << t1 << "\n";
  ++t1;
  cout << "t1 = " << t1 << "\n";
  t1 += 100;
  cout << "t1 = " << t1 << "\n";
  t1 -= Time(100);
  cout << "t1 = " << t1 << "\n";
  Time t2(9,55,12.3456789);
  cout << "t2 = " << t2 << "\n";
  if (t1 < t2) cout << "t1 < t2" << "\n";
  else cout << "t1 >= t2" << "\n";
  Time t3(123456.789);
  Time t4(12.3456789);
  cout << "t3 = " << t3 << "\n";
  cout << "t4 = " << t4 << "\n";
  cout << "t3 + t4 = " << t3 + t4 << "\n";
  cout << "t3 - t4 = " << t3 - t4 << "\n";
  cout << "t3 + 100.0 = " << t3 + 100.0 << "\n";
  cout << "t3 - 100.0 = " << t3 - 100.0 << "\n";
  string str = t3.toString();
  cout << "t3.toString() = " << str << "\n";
  cout << "t3.toString() = " << t3.toString() << "\n";
}
