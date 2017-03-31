//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.14 on page 148
//  A subclass for self-organizing lists

template <class T>
class SelfOrganizingList : public list<T>
{ public:
    bool contains(const T&);
};
template <class T>
bool SelfOrganizingList<T>::contains(const T& t)
{ list<T>::iterator it=find(begin(),end(),t);
  if (it == end()) return false;
  if (it != begin())
  { erase(it);
    push_front(t);
  }
  return true;
}
