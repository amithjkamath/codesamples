//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 5.1 page 105
//  Testing the Calculator class

template <class T> void reverse(Stack<T>& s)
{ Stack<T> ss=s;
  while (!s.empty())
    s.pop();
  while (!ss.empty())
  { s.push(ss.top());
    ss.pop();
  }
}
