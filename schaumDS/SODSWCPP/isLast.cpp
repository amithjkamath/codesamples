// This is incorrect.
// I could not solve this problem:
//   return true iff *it is the last memeber of his generation.

template <class T>
bool Tree<T>::isLast(Iterator it)
{ if (empty() || !it) return false;
  Tree::Node* p = *(_nodes.begin());  // root
  if (p == it._p) return true;
  NPList list = p->_children;
  while (!(list.empty()))
  { p = list.back();
    if (p==it._p) return true;
    list = p->_children;
  }
  return false;
}

