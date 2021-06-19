//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Tree.cpp 
//  Test driver for Tree class template

#include "Tree.1.hpp"
void test(string);
typedef Tree<char> CTree;
typedef CTree::Iterator CTIt;
  
int main()
{ test("");
  test("A");
  test("A+B");
  test("A+B+C+D+E+F+G");
  test("A+B+C+D--E+F+G");
  test("A+B+CDE-F+G");
  test("A+B+C+D-E-FG");
  test("A+BC+D+E+F---G");
  test("A+BCDEFG");
  test("A+B+CDEFG");
  test("A+BC+DEFG");
  typedef Tree<char> CTree;
  typedef CTree::Iterator CTIt;
  istringstream in("A+B+CDE-F+G");
  CTree t;
  in >> t;
  CTIt it=t.begin();
  ++it;
  cout << "*it= " << *it << ", t= " << t << "\n";
  *it = 'Z';
  t.clear();
  cout << "t= " << t << "\n";
}

void test(string s)
{ typedef Tree<char> CTree;
  typedef CTree::Iterator CTIt;
  istringstream in(s);
  CTree t;
  in >> t;
  for (CTIt it=t.begin(); it!=t.end(); it++)
  { 
    if (t.isOldest(it)) cout << "o";
    if (t.isYoungest(it)) cout << "y";
    cout << *it;
  }
  cout << ":\nsize=" << t.size() << ", height=" << t.height()
       << ", degree=" << t.degree();
  if (!t.empty()) cout << ", root=" << t.root();
  cout << "; " << t << " = " << s << "\n";
  t.print();
  for (CTIt it=t.begin(); it!=t.end(); it++)
    cout << "level(" << *it << ")=" << t.level(it)
         << ", degree(" << *it << ")=" << degree(it) << "\n";
  t.print(1);
  t.print(2);
}

