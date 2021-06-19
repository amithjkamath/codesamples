//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  HashTable.hpp
//  Interface and implementation of HashTable class template
//  Uses separate chaining

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
    typedef list<Pair> List;
    typedef vector<List> Vector;
    typedef List::iterator LIt;
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
{ int k=hash(key);
  List& chain=_[k];
  for(LIt jt=chain.begin(); jt!=chain.end(); jt++)
    if (jt->first == key) return jt->second;             // found
  if (size()+1 < LOAD*_.size())
  { chain.push_front(Pair(key,T()));
    return chain.front().second;
  }
  else
  { rebuild();
    return operator[](key);
  }
}

template <class K, class T, class H>
bool HashTable<K,T,H>::insert(K key, T val)
{ int k=hash(key);
  List& chain=_[k];
  for(LIt jt=chain.begin(); jt!=chain.end(); jt++)
    if (jt->first == key) return false;    // found: no insertion
  if (size()+1 < LOAD*_.size()) chain.push_front(Pair(key,val));
  else
  { rebuild();
    insert(key,val);
  }
  return true;
}

template <class K, class T, class H>
bool HashTable<K,T,H>::remove(K key)
{ int k=hash(key);
  List& chain=_[k];
  for(LIt jt=chain.begin(); jt!=chain.end(); jt++)
    if (jt->first == key)                   // found: remove pair
    { chain.erase(jt);
      return true;
    }
  return false;                          // not found: no removal
}

template <class K, class T, class H>
int HashTable<K,T,H>::size() const
{ int n=0;
  for (CVIt it=_.begin(); it!=_.end(); it++)
    n += it->size();                 // accumulate the list sizes
  return n;
}

template <class K, class T, class H>
void HashTable<K,T,H>::dump() const
{ for (int i=0; i<_.size(); i++)
  { List chain=_[i];
    if (!chain.empty())
    { LIt jt=chain.begin();
      cout << i << ": ("
           << jt->first << ": " << jt->second << ")";
      while (++jt!=chain.end())
        cout << ", (" << jt->first << ": " << jt->second << ")";
      cout << "\n";
    }
  }
}

template <class K, class T, class H>
int HashTable<K,T,H>::hash(K key)
{ return _hash(key)%_.size();
}

template <class K, class T, class H>
void HashTable<K,T,H>::rebuild()
{ Vector old_(_);                          // copy current vector
  _ = Vector(4*_.size()+3);            // create new larger table
  for (VIt it=old_.begin(); it!=old_.end(); it++)
    for(LIt jt=it->begin(); jt!=it->end(); jt++)
      insert(jt->first,jt->second);   // rehash to load new table
}

#endif  // HASH_TABLE_
