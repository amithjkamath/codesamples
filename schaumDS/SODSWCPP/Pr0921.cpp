//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.21 on page 188
//  A width(int) function member of the Tree class

List level(int n);   // returns list of all nodes at level n

int Tree::width(int n)
{ return level(n).size();
}

List Tree::level(int n)
{ List listn;
  if (empty()) return listn;
  queue<List*> q;
  Node* root=*(_nodes.begin());           // points to root
  if (n==0) return List(1,root);
  q.push(&(root->_children));
  while (!q.empty())
  { List* p=q.front();
    List& list=*p;
    for (LIt lit=list.begin(); lit!=list.end(); lit++)
    { Node* p=*lit;
      It it(this,*lit);
      if (level(it)==n)
        listn.push_back(*lit);
      q.push(&((*lit)->_children));
    }
    q.pop();
  }
  return listn;
}
