//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.28 on page 189
//  A defoliate() function member for the Tree class

void Tree::defoliate()
{ if (_nodes.size() < 2)
  { clear();
    return;
  }
  for (LIt lit=_nodes.begin(); lit!=_nodes.end(); lit++)
  { Node* p=*lit;
    if (p->_children.empty())
    { p->_parent->_children.clear();
      delete p;
      LIt tmp=lit;
      --lit;    // save location in _nodes list
      _nodes.erase(tmp);
    }
  }
}
