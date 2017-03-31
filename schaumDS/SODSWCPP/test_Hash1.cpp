//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Hash.cpp 
//  Test driver for Hash function struct template

#include <iostream>  // defines cout object
using namespace std;
#include "Hash1.hpp"

int main()
{ Hash h;
  cout << "h(\"Mercury\")\t= " << h("Mercury") << "\n";
  cout << "h(\"Venus\")\t= "   << h("Venus") << "\n";
  cout << "h(\"Earth\")\t= "   << h("Earth") << "\n";
  cout << "h(\"Mars\")\t= "    << h("Mars") << "\n";
  cout << "h(\"Jupiter\")\t= " << h("Jupiter") << "\n";
  cout << "h(\"Saturn\")\t= "  << h("Saturn") << "\n";
  cout << "h(\"Uranus\")\t= "  << h("Uranus") << "\n";
  cout << "h(\"Neptune\")\t= " << h("Neptune") << "\n";
  cout << "h(\"Pluto\")\t= "   << h("Pluto") << "\n";
}
