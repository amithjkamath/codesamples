//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 10.32 on page 218
//  A defoliate() function member for the BinaryTree class

void d(Node*,It);

void BinaryTree::defoliate()
{ if (!_root) return;
  if (_root->_left || _root->_right) d(_root);
  else clear();
}

void d(Node* p)
{ // precondition: *p is not a leaf
  Node* lc=p->_left;
  if (lc && (lc->_left || lc->_right)) d(lc);
  else  // *lc is a leaf
  { delete lc;
    p->_left = 0;
  }
  Node* rc=p->_right;
  if (rc && (rc->_left || rc->_right)) d(rc);
  else  // *rc is a leaf
  { delete rc;
    p->_right = 0;
}
