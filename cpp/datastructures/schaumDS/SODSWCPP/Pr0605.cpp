//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 6.5 page 121
//  Another asssignment operator for queues

bool queue::operator+=(const queue& s)
{ queue ss=s, s2;
  while (!ss.empty())
  { s2.push(ss.back());
    ss.pop();
  }
  while (!s2.empty())
  { push(s2.back());
    s2.pop();
  }
}
