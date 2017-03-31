//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.34 on page 189
//  A detach() function member for the Tree class

void Tree::detach(Iterator it, Tree& tree)
{ // PRECONDITION: it is an iterator on this tree;
  // if t is empty or if (it == tree.end()),
  //   then t is left unchanged and t1 returns empty;
  // if (it == tree.begin()), then t1 is replaced by t
  //   and t returns empty;
  // POSTCONDITIONS: the previous contents of t1 are lost;
  //   t1 contains the nodes that were in the subtree of t
  //   rooted at it;
  t1._nodes.clear();
  if (_nodes.empty() || it == end()) return;    // t1 empty
  if (it == begin())
  { t1._nodes = _nodes;          // copy entire _nodes list
    _nodes.clear();                    // empty _nodes list
    return;
  }
  // move [lit1,lit2[ from _nodes to t1._nodes:
  LIt lit1=it._lit;
  LIt lit2=_nodes.end();
  for (Node* p=*lit1; lit2 == _nodes.end() && p != p->_parent;
       p = p->_parent)
    lit2=nextSibling(litn(p));
  t1._nodes.insert(t1._nodes.end(),lit1,lit2);
  _nodes.erase(lit1,lit2);
  // reset node pointers to disconnect subtree:
  Node* p1=*lit1;            
  Node* pp=p1->_parent;     
  List& pplist=pp->_children;
  LIt pplit1=litp(p1);      // p1's parent's pointer to *it
  pplist.erase(pplit1);
  p1->_parent = p1;      // *p1 is the root of the subtree
}
