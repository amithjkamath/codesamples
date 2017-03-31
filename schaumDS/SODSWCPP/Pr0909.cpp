//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.9 on page 187
//  A level() function member of the Tree class

int l(Node*,Iterator);

bool Tree::level(Iterator it) const
{ return l(_nodes.front(),it);
}

int l(Node* p, Iterator it)
{ if (!p) return -1;  // the empty tree has height -1
  if (p->_ == *it) return 0;         // *it was found
  List& plist=p->_children;
  for (LIt plit=plist.begin(); plit!=plist.end(); plit++)
  { int lc=l(*plit,it);
    if (lc>-1) return lc+1;
  }
  return -1;  // *it is not in this subtree
}
