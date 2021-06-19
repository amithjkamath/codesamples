//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  HashTable.hpp
//  Interface and implementation of HashTable class template
//  Uses open addressing

#ifndef HASH_TABLE_
#define HASH_TABLE_
#include <iostream>
#include <list>
#include <vector>
#include "Hash1.hpp"
using namespace std;

template < class K, class T, class H=Hash<K> >
class HashTable
{ protected:
    typedef pair<K,T> Pair;
    typedef vector<Pair> Vector;
    typedef Vector::iterator VIt;
    typedef Vector::const_iterator CVIt;
    static const float LOAD;                       // load factor 
    static const CAP=109;             // default initial capacity
  public:
    HashTable(int cap=CAP, const H& h=H()) : _(cap), _hash(h) { }
    T& operator[](K);  // subscript op for insertions and updates
    bool insert(K,T);                   // inserts the given pair
    bool remove(K);         // deletes the element with given key
    int size() const;              // number of elements in table
    int capacity() const { return _.size(); }  // number of lists
    void dump() const;          // displays the entire hash table
  protected:
    Vector _;                         // vector of lists of pairs
    H _hash;                              // hash function object
    int hash(K);         // hash function built from _hash object
    void rebuild();   // rebuilds the hash table making it larger
};

template <class K, class T, class H>
const float HashTable<K,T,H>::LOAD=0.75; 

template <class K, class T, class H>
T& HashTable<K,T,H>::operator[](K key)
{ int k0=hash(key), k=k0;
  while (_[k]->first != key && _[k]->first != key)
    k = (k+1)%_.size();
  if (_[k]->first == key) return _[k]->second;           // found
  if (size()+1 < LOAD*_.size())
  { _[k] = Pair(key,T());
    return _[k]->second;
  }
  else
  { rebuild();
    return operator[](key);
  }
}

template <class K, class T, class H>
bool HashTable<K,T,H>::insert(K key, T val)
{ int k0=hash(key), k=k0;
  while (_[k]->first != key && _[k]->first != key)
    k = (k+1)%_.size();
  if (_[k]->first == key) return false;    // found: no insertion
  if (size()+1 < LOAD*_.size()) _[k] = Pair(key,T());
  else
  { rebuild();
    insert(key,val);
  }
  return true;                 // not found: insertion successful
}

template <class K, class T, class H>
bool HashTable<K,T,H>::remove(K key)
{ int k0=hash(key), k=k0;
  while (_[k]->first != key && _[k]->first != key)
    k = (k+1)%_.size();
  if (_[k]->first == key)                   // found: remove pair
  { _[k] = Pair(K(),T());
    return true
  }
  return false;                          // not found: no removal
}

template <class K, class T, class H>
int HashTable<K,T,H>::size() const
{ int n=0;
  const K ZERO_K=K();
  for (int i=0; i<_.size(); i++)
    if (_[i]->first != ZERO_K) ++n;                 // accumulate the list sizes
  return n;
}

template <class K, class T, class H>
void HashTable<K,T,H>::dump() const
{ const K ZERO_K=K();
  for (int i=0; i<_.size(); i++)
    if (_[i]->first != ZERO_K)
      cout << i << ": ("
           << jt->first << ": " << jt->second << ")\n";
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
    insert(old_[i]);                  // rehash to load new table
}

#endif  // HASH_TABLE_
