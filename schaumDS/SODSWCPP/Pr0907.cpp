//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.7 on page 187
//  A leaves() function member of the Tree class

int n(Node*);

int Tree::leaves() const
{ return n(_nodes.front());
}

int n(Node* p)
{ if (!p) return 0;
  List& plist=p->_children;
  if (plist.empty()) return 1;  // *p is a leaf
  int n0=0;
  for (LIt plit=plist.begin(); plit!=plist.end(); plit++)
    n0 += n(*plit);
  return n0;
}
