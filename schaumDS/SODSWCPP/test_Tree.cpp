//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Tree.cpp 
//  Test driver for string Tree class

#include "Tree.h"
#include <fstream>
#include <iostream>
using namespace std;
typedef Tree::Iterator It;
typedef list<Tree*> TList;
typedef TList::iterator TLIt;
typedef TList::const_iterator TLCIt;
void test(const char*);
void print(Tree&);

const int NUM=0;

int main()
{ TList tlist;
  tlist.push_back(new Tree("Cohen"));
  tlist.push_back(new Tree("Davis"));
  tlist.push_back(new Tree("Evans"));
  Tree t0("Baker",tlist);
  for (It it=t0.begin(); it!=t0.end(); it++)
    cout << *it << " ";
  cout << "\n";
  tlist.clear();
  tlist.push_back(new Tree("Gauss"));
  Tree t1("Foley",tlist);
  for (It it=t1.begin(); it!=t1.end(); it++)
    cout << *it << " ";
  cout << "\n";
  tlist.clear();
  tlist.push_back(&t0);
  tlist.push_back(&t1);
  Tree t("Adams",tlist);
  for (It it=t.begin(); it!=t.end(); it++)
    cout << *it << " ";
  cout << "\n";
  cout << "\tsize=" << t.size() << "\n";
  cout << "\tleaves=" << t.leaves() << "\n";
  cout << "\theight=" << t.height() << "\n";
  for (It it=t.begin(); it!=t.end(); it++)
    cout << "\tlevel(" << *it << ")=" << t.level(it) << "\n";
  cout << "\tpath length=" << t.pathLength() << "\n";
  for (It it=t.begin(); it!=t.end(); it++)
    cout << *it << ", isRoot=" << isRoot(it)
         << ", isLeaf=" << isLeaf(it) << "\n";
  cout << "\troot=" << t.root() << "\n";
  It it=t.begin();
  ++it;
  cout << "*it=" << *it << "\n";
  for (It jt=t.begin(); jt!=t.end(); jt++)
    cout << "*jt=" << *jt
         << ", generations=" << t.generations(it,jt) << "\n";
  for (It jt=t.begin(); jt!=t.end(); jt++)
  { cout << "*jt=" << *jt;
    it=t.parent(jt);
    if (it!=t.end()) cout << ", parent=" << *it;
    cout << "\n";
  }
  for (It jt=t.begin(); jt!=t.end(); jt++)
    cout << "*jt=" << *jt
         << ", children=" << numChildren(jt) << "\n";
  for (It jt=t.begin(); jt!=t.end(); jt++)
  { cout << "*jt=" << *jt;
    if (isOldestChild(jt)) cout << " is oldest.";
    if (isYoungestChild(jt)) cout << " is youngest.";
    cout << "\n";
  }
  for (It jt=t.begin(); jt!=t.end(); jt++)
  { cout << "*jt=" << *jt;
    if (!isLeaf(jt))
      cout << ", oldestChild= " << *oldestChild(jt)
           << ", youngestChild= " << *youngestChild(jt);
    cout << "\n";
  }
  cout << "\twidth(0)=" << t.width(0) << "\n";
  cout << "\twidth(1)=" << t.width(1) << "\n";
  cout << "\twidth(2)=" << t.width(2) << "\n";
  cout << "\twidth()=" << t.width() << "\n";
  t.print(0);
  t.print(1);
  t.print(2);
  t.print();
  t0 = t;
  if (t0 == t) cout << "t0 == t\n";
  else cout << "t0 != t\n";
  if (t0 != t) cout << "t0 != t\n";
  else cout << "t0 == t\n";
  it=t0.begin();
  *it = "Quinn";
  if (t0 == t) cout << "t0 == t\n";
  else cout << "t0 != t\n";
  if (t0 != t) cout << "t0 != t\n";
  else cout << "t0 == t\n";
  t0.print();
  t0.reflect();
  t0.print();
  t0.defoliate();
  t0.print();
}  
