//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Planet.cpp 
//  Test driver for Planet class template

#include <fstream>   // defines ifstream class
#include <iostream>  // defines cout object
using namespace std;
#include "Planet.hpp"

int main()
{ Planet p;
  ifstream fin("Planets.dat");
  string str;
  while (getline(fin,str))
  { istringstream in(str);
    in >> p;
    cout << p << "\n";
  }
}
