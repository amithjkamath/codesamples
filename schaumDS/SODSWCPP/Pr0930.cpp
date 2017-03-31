//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.30 on page 189
//  An erase() function member for the Tree class

void Tree::erase(Iterator it)
{ if (!it) return;
  Node* p=(*it._lit);
  Node* pp=p->_parent;
  if (p->_children.empty())                 // *p is a leaf
  { LIt lit = find(_nodes.begin(),_nodes.end(),p);
    _nodes.erase(lit);
    if (pp != p)                      // *p is not the root
    { List& list = pp->_children;
      lit = find(list.begin(),list.end(),p);
      list.erase(lit);
    }
    delete p;
  }
  else                      // replace *p with oldest child
  { p->_ = p->_children.front()->_;
    erase(It(this,p->_children.front()));
  }
}
