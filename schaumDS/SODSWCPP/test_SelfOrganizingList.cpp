//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_SelfOrganizingList.cpp 
//  Terst driver for SelfOrganizingList subclass template

#include "SelfOrganizingList.hpp"

int main()
{ SelfOrganizingList<string> l;
  l.push_back("piccolo");
  l.push_back("bassoon");
  l.push_back("trumpet");
  l.push_back("timpani");
  cout << l.front() << '\n';
  if (l.contains("trumpet")) cout << l.front() << '\n';
  if (l.contains("bassoon")) cout << l.front() << '\n';
  if (l.contains("timpani")) cout << l.front() << '\n';
}
