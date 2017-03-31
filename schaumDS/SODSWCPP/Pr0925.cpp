//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.25 on page 188
//  An equality operator for the Tree class

bool Tree::operator==(const Tree& t) const
{ if (_nodes.size() != t._nodes.size()) return false;
  LCIt tlit=t._nodes.begin();
  for (LCIt lit=_nodes.begin(); lit!=_nodes.end(); lit++, tlit++)
    if ((*lit)->_ != (*tlit)->_) return false;
  return true;
}
