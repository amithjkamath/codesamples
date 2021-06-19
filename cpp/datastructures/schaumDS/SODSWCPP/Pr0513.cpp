//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 5.8 page 104
//  An overloaded assignment operator for stacks

bool Stack::operator+=(const Stack& s)
{ Stack ss=s, s2;
  while (!ss.empty())
  { s2.push(ss.top());
    ss.pop();
  }
  while (!s2.empty())
  { push(s2.top());
    s2.pop();
  }
}
