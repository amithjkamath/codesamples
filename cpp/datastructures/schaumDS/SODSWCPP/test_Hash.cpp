//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Hash.cpp 
//  Test driver for Hash function struct template

#include <iostream>  // defines cout object
using namespace std;
#include "Hash1.hpp"
void print(const string&);

int main()
{ print("Ruf");
  print("Eis");
  print("Tor");
  print("Ast");
  print("Zug");
  print("Hof");
  print("Rat");
  print("Lob");
  print("Mut");
  print("Tat");
  print("Ohr");
  print("Mal");
}

void print(const string& s)
{ Hash<string> h;
  int n=h(s);
  cout << "h(" << s << ") = " << n
       << "\t" << n%23 << "\n";
}
