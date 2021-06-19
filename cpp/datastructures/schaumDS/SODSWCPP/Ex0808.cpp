//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.8 on page 162
//  Interface for a Hash function template

template <class K>
struct Hash
{ int operator()(K s)
  { int h=0;
    for (int i=0; i<s.length(); i++)
      h += s[i];
    return h;
  }
};
