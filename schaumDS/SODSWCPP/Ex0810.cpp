//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.10 on page 163
//  Implementation of a HashTable class template

#include "HashTable.h"
#include "Hash.h"

template <class K, class T, class H>
const float HashTable<K,T,H>::LOAD=0.75; 

template <class K, class T, class H>
T& HashTable<K,T,H>::operator[](K key)
{ const K ZERO_K=K();
  int k0=hash(key), k=k0;
  while (_[k].first != key && _[k].first != ZERO_K)
    k = (k+1)%_.size();
  if (_[k].first == key) return _[k].second;           // found
  if (size()+1 < LOAD*_.size())
  { _[k] = Pair(key,T());
    return _[k].second;
  }
  else
  { rebuild();
    return operator[](key);
  }
}

template <class K, class T, class H>
bool HashTable<K,T,H>::insert(K key, T val)
{ const K ZERO_K=K();
  int k0=hash(key), k=k0;
  while (_[k].first != key && _[k].first != ZERO_K)
    k = (k+1)%_.size();
  if (_[k].first == key) return false;    // found: no insertion
  if (size()+1 < LOAD*_.size()) _[k] = Pair(key,val);
  else
  { rebuild();
    insert(key,val);
  }
  return true;                 // not found: insertion successful
}

template <class K, class T, class H>
bool HashTable<K,T,H>::remove(K key)
{ int k0=hash(key), k=k0;
  while (_[k].first != key && _[k].first != key)
    k = (k+1)%_.size();
  if (_[k].first == key)                   // found: remove pair
  { _[k] = Pair(K(),T());
    return true;
  }
  return false;                          // not found: no removal
}

template <class K, class T, class H>
int HashTable<K,T,H>::size() const
{ int n=0;
  const K ZERO_K=K();
  for (int i=0; i<_.size(); i++)
    if (_[i].first != ZERO_K) ++n;   // accumulate the list sizes
  return n;
}

template <class K, class T, class H>
void HashTable<K,T,H>::dump() const
{ const K ZERO_K=K();
  for (int i=0; i<_.size(); i++)
    if (_[i].first != ZERO_K)
      cout << i << ": ("
           << _[i].first << ": " << _[i].second << ")\n";
}

template <class K, class T, class H>
int HashTable<K,T,H>::hash(K key)
{ return _hash(key)%_.size();
}

template <class K, class T, class H>
void HashTable<K,T,H>::rebuild()
{ Vector old_(_);                          // copy current vector
  _ = Vector(4*_.size()+3);            // create new larger table
  for (int i=0; i<old_.size(); i++)
    insert(old_[i].first,old_[i].second);  // rehash to new table
}