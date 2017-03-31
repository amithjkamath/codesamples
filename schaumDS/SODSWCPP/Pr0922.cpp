//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.22 on page 188
//  A width() function member of the Tree class

int Tree::width()
{ if (_nodes.empty()) return 0;               // empty tree
  int w=1;
  for (int k=0; k<=height(); k++)
  { int w1=level(k).size();      // number of nodes at level k
    if (w1>w) w = w1;
  }
  return w;
}
