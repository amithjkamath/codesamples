//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.12 on page 166
//  Using A permutation-sensitive hash function

template <class K>
struct Hash
{ // PRECONDITION: K == string
  int operator()(K s)
  { int h=0;
    for (int i=0; i<s.length(); i++)
      h += i*s[i];
    return h;
  }
}
