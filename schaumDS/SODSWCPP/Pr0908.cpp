//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.8 on page 187
//  A height() function member of the Tree class

int h(Node*);

int Tree::height() const
{ if (_nodes.empty()) return -1;
  else return h(_nodes.front());
}

int h(Node* p)
{ if (!p) return -1;  // the empty tree has height -1
  List& plist=p->_children;
  if (plist.empty()) return 0;
  int h0=0;
  for (LIt plit=plist.begin(); plit!=plist.end(); plit++)
  { int h1=h(*plit);
    if (h1>h0) h0 = h1;
  }
  return h0+1;
}
