//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.14 on page 188
//  A generations() function member of the Tree class

int Tree::generations(Iterator it, Iterator jt) const
{ if (!it || !jt) return -1;
  if (it == jt) return 0;
  int n=0;
  Node* p=(*jt._lit)->_parent;
  while (jt != it && p != *jt._lit)
  { Tree* tp=this;
    p=(*jt._lit)->_parent;
    jt = It(tp,p);
    ++n;
  }
  if (jt == it) return n;
  n = generations(jt,it);
  if (n != -1 && !!it && !!jt) return -n;
  return -1;
}
