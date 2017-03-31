//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.33 on page 189
//  An attach() function member for the Tree class

Iterator Tree::attach(Iterator it, Tree& tree)
{ // PRECONDITION: it is an iterator on this tree;
  // if t is empty, it is replaced by t1;
  // if t1 is empty, there is no change;
  // otherwise, if (it == tree.begin()), the root of t1
  //   becomes the new root of t and the old root 
  //   becomes its youngest child; 
  // otherwise, if (it == tree.end()), the root of t1
  //   becomes the youngest child of the root of t; 
  // otherwise, t1 is inserted in front of *it,
  //   becoming its next older sibling;
  // POSTCONDITIONS: t1 returns empty;
  //   it locates the root of the subtree that was t1;
  if (t1._nodes.empty()) return it;  // no change
  // move t1._nodes list into _nodes list:
  LIt lit1=t1._nodes.begin();
  LIt lit2=it._lit;
  Node* p1=*lit1;                   // points to root of t1
  _nodes.insert(lit2,lit1,t1._nodes.end());
  t1._nodes.clear();
  // connect parent and children links:
  if (p1 == _nodes.front())         // *p1 is the new root:
    if (lit2 == _nodes.end()) ;           // tree was empty
    else    // make old root the youngest child of new root
    { Node* p2=*lit2;                 // points to *it node
      (p1->_children).push_back(p2);
      p2->_parent = p1;
    }
  else // root does not change
    if (lit2 == _nodes.end())  // t1 youngest child of root
    { Node* p2=_nodes.front();
      List& pplist=p2->_children;
      pplist.push_back(p1);
      p1->_parent = p2;
    }
    else
    { Node* p2=*lit2;                 // points to *it node
      List& pplist=p2->_parent->_children;
      LIt litp2=litp(p2);           // locates p2 in pplist
      pplist.insert(litp2,p1);
      p1->_parent = p2->_parent;
    }
  return It(this,lit1);
}
