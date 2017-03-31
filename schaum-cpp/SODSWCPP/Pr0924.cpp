//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.24 on page 188
//  A print() function member of the Tree class

void Tree::print()
{ int h=height();
  for (int level=0; level<=h; level++)
    print(level);
}
