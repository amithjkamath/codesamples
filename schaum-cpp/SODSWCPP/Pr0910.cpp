//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.10 on page 187
//  A pathLength() function member of the Tree class

int Tree::pathLength()
{ int pl=0;
  for (LIt lit=_nodes.begin(); lit!=_nodes.end(); lit++)
    pl += level(It(this,*lit));
  return pl;
}
