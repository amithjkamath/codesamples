//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.15 on page 168
//  Interface for a Hash function class template

template <class K>
struct Hash
{ int operator()(K s)
  { int h=0;
    for (int i=0; i<s.length(); i++)
      h += s[i];
    return h;
  }
};
