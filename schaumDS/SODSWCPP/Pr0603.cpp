//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 6.3 page 121
//  Overloading the equality operator for queues

bool queue::operator==(const queue s)
{ queue s1=s, s2=*this;
  while (!s1.empty())
    if (s1.back() != s2.back()) return false;
    else
    { s1.pop();
      s2.pop();
    }
  return true;
}
