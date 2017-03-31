//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.31 on page 189
//  A grow() function member for the Tree class

Iterator Tree::grow(Iterator it, const Type& x)
{ LIt lit=it._lit;        // locates current node in _nodes
  Node* pp=*lit;
  Node* p=new Node(x,pp);
  pp->_children.push_back(p);
  Node* ppp=pp->_parent;
  List& ppplist=ppp->_children;
  if ( (ppp == pp)                       // *pp is the root
    || (pp == ppplist.back()) )    // or pp is the youngest
  { _nodes.push_back(p);
    lit=find(lit,_nodes.end(),p);
  }
  else                // find next sibling of pp in _nodes:
  { LIt ppplit=find(ppplist.begin(),ppplist.end(),pp);
    ++ppplit;                 // locates next sibling of pp
    lit=find(lit,_nodes.end(),*ppplit);
    lit = _nodes.insert(lit,p);  
  }
  return It(this,lit);
}
