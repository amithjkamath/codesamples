//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.14 on page 167
//  Interface for a HashTable class template

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
}
