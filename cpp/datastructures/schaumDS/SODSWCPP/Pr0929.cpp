//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.29 on page 189
//  An insert() function member for the Tree class

LIt Tree::litn(Node* p)
{ // returns the LIt for _nodes that locates p:
  if (p == 0) return LIt();  
  return find(_nodes.begin(),_nodes.end(),p);
}
LIt Tree::litp(Node* p)
{ // returns the LIt for p->_parent that locates p:
  if (p == 0 || p == _nodes.front()) return LIt();  
  List& pplist=p->_parent->_children;
  return find(pplist.begin(),pplist.end(),p);
}
LIt Tree::prevSibling(LIt lit)
{ // returns the LIt for _node that locates
  // the next older sibling of *lit
  if (_nodes.empty() || lit==_nodes.begin())
    return _nodes.end();  
  if (lit==_nodes.end()) return _nodes.begin();  
  Node* p1=*lit;
  LIt litp1=litp(p1);
  if (p1 == (p1->_parent->_children).front())
    return _nodes.end();
  return find(_nodes.begin(),--lit,*--litp1);
}
LIt Tree::nextSibling(LIt lit)
{ // returns the LIt for _node that locates
  // the next younger sibling of *lit
  if (lit==_nodes.begin() || lit==_nodes.end())
    return _nodes.end();  
  Node* p2=*lit;
  LIt litp2=litp(p2);
  if (p2 == (p2->_parent->_children).back())
    return _nodes.end();
  return find(++lit,_nodes.begin(),*++litp2);
}

Iterator Tree::insert(Iterator it, const Type& x)
{ // new node is new parent of *it
  // _nodes maintains preorder traversal
  Node* np = new Node(x);
  if (!it)              // insert at (preorder) end of tree
  { Node* pp = _nodes.back();
    pp->_children.push_back(np);
    _nodes.push_back(np);
  }
  else
  { Node* p=(*it._lit);
    Node* pp=p->_parent;
    np->_children.push_back(p);
    LIt lit = find(_nodes.begin(),_nodes.end(),p);
    _nodes.insert(lit,np);
    if (pp != p)                      // *p is not the root
    { List& list = pp->_children;
      lit = find(list.begin(),list.end(),p);
      *lit = np;               // make *np the child of *pp
    }
  }
  return It(this,np);
}
